#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

// #define NGDBG

const double EPS = 1e-7;

struct Point {
    double x, y;
    friend ostream &operator<<(ostream &o, const Point &p) {
        return o << "Point (" << p.x << ", " << p.y << ")";
    }
    Point polar(const double r, const double angle) const {
        return {x + r * cos(angle), y + r * sin(angle)};
    }
    bool is_equal(const Point &rhs) const {
        return abs(x - rhs.x) < EPS && abs(y - rhs.y) < EPS;
    }
};

struct Vec {
    double x, y;
    friend ostream &operator<<(ostream &o, const Vec &v) {
        return o << "Vec (" << v.x << ", " << v.y << ')';
    }
    Vec(double x, double y) : x(x), y(y) {}
    Vec(const Point &p1, const Point &p2) { x = p2.x - p1.x, y = p2.y - p1.y; }
    double cross(const Vec &rhs) const { return x * rhs.y - rhs.x * y; }
    double dot(const Vec &rhs) const { return x * rhs.x + y * rhs.y; }
    double length(void) const { return sqrt(x * x + y * y); }
    double angle(void) const { return atan2(y, x); }
    Vec normal(void) const {
        double len = this->length();
        return {x / len, y / len};
    }
    Vec rotate(const double angle) const {
        double cosA = cos(angle), sinA = sin(angle);
        return {cosA * x - sinA * y, sinA * x + cosA * y};
    }
    Vec operator*(const double r) const { return {x * r, y * r}; }
    Point operator+(const Point &p) const { return {p.x + x, p.y + y}; }
};

struct Line {
    Point p1, p2;
    friend ostream &operator<<(ostream &o, const Line &l) {
        return o << "Line { " << l.p1 << ", " << l.p2 << " }";
    }
    Line upper_parallel(const double distance) const {
        double k = (p2.y - p1.y) / (p2.x - p1.x);
        double theta = atan(abs(k));
        double dy = distance * cos(theta);
        double dx = distance * sin(theta);
        if (k > 0) {
            return {{p1.x - dx, p1.y + dy}, {p2.x - dx, p2.y + dy}};
        } else {
            return {{p1.x + dx, p1.y + dy}, {p2.x + dx, p2.y + dy}};
        }
    }
    double length(void) const { return Vec(p1, p2).length(); }
    bool contains(const Point &p) const {
        Vec v1(p1, p2), v2(p1, p);
        double l1 = v1.length(), l2 = v2.length();
        return abs(v1.dot(v2) - l1 * l2) < EPS && l2 <= l1;
    }
    Vec to_vec(void) const { return Vec(p1, p2); }
    double length(const Point &p) const { return Vec(p1, p).length(); }
};

struct Arc {
    Point o, p1, p2;
    double r;
    friend ostream &operator<<(ostream &o, const Arc &a) {
        return o << "Arc { " << a.o << ", " << a.p1 << ", " << a.p2 << ", "
                 << a.r << " }";
    }
    double angle(const Point &p) const {
        double a1 = Vec(o, p1).angle(), a2 = Vec(o, p2).angle();
        double angle = Vec(o, p).angle();
        if (a1 >= a2) {
            return a1 - angle;
        } else {
            return a1 - angle + M_PI * 2;
        }
    }
    // do not check radius
    bool contains(const Point &p) const {
        double a1 = Vec(o, p1).angle(), a2 = Vec(o, p2).angle();
        double angle = Vec(o, p).angle();
        if (a1 >= a2) {
            return angle <= a1 && angle >= a2;
        } else {
            return angle <= a1 || angle >= a2;
        }
    }
    double length(void) const {
        double a1 = Vec(o, p1).angle(), a2 = Vec(o, p2).angle();
        if (a1 >= a2) {
            return r * (a1 - a2);
        } else {
            return r * (a1 - a2 + M_PI * 2);
        }
    }
};

int intersection(vector<Point> &v, const Line &lhs, const Line &rhs) {
    const Point &p1 = lhs.p1, &p2 = lhs.p2;
    const Point &q1 = rhs.p1, &q2 = rhs.p2;

    bool test1 = min(p1.x, p2.x) <= max(q1.x, q2.x) &&
                 min(q1.x, q2.x) <= max(p1.x, p2.x) &&
                 min(p1.y, p2.y) <= max(q1.y, q2.y) &&
                 min(q1.y, q2.y) <= max(p1.y, p2.y);
    if (!test1) {
        return 0;
    }

    Vec v1(q1, p1), v2(q1, p2), v3(q1, q2);
    bool test2 = v1.cross(v3) * v2.cross(v3) < 0;

    v1 = Vec(p1, q1), v2 = Vec(p1, q2), v3 = Vec(p1, p2);
    test2 &= v1.cross(v3) * v2.cross(v3) < 0;

    if (!test2) {
        return 0;
    }

    Vec base(q1, q2);
    double d1 = abs(base.cross(Vec(p1, q1)));
    double d2 = abs(base.cross(Vec(p2, q1)));
    double t = d1 / (d1 + d2);
    Vec tv(p1, p2);
    v.push_back(Point{p1.x + tv.x * t, p1.y + tv.y * t});
    return 1;
}

int intersection(vector<Point> &v, const Arc &lhs, const Line &rhs) {
    Vec v1(lhs.o, rhs.p1), v2(lhs.o, rhs.p2);
    double angle = rhs.to_vec().angle();
    Vec v3 = v1.rotate(-angle);

    double y = v3.y;
    if (y > lhs.r || y < -lhs.r) {

        return 0;
    }
    double x = sqrt(lhs.r * lhs.r - y * y);

    Point p1 = Vec(x, y).rotate(angle) + lhs.o;
    Point p2 = Vec(-x, y).rotate(angle) + lhs.o;

    int cnt = 0;
    if (lhs.contains(p1) && rhs.contains(p1)) {
        v.push_back(p1);
        ++cnt;
    }

    if (!p1.is_equal(p2) && lhs.contains(p2) && rhs.contains(p2)) {
        v.push_back(p2);
        ++cnt;
    }
    return cnt;
}

int intersection(vector<Point> &v, const Line &lhs, const Arc &rhs) {
    return intersection(v, rhs, lhs);
}

int intersection(vector<Point> &v, const Arc &lhs, const Arc &rhs) {
    double d = Vec(lhs.o, rhs.o).length();
    if (d > lhs.r + rhs.r) {
        return 0;
    }

    double delta_angle =
        acos((lhs.r * lhs.r + d * d - rhs.r * rhs.r) / (2 * lhs.r * d));
    double angle = Vec(lhs.o, rhs.o).angle();
    Point p1 = lhs.o.polar(lhs.r, angle + delta_angle);
    Point p2 = lhs.o.polar(lhs.r, angle - delta_angle);

    int cnt = 0;
    if (lhs.contains(p1) && rhs.contains(p1)) {
        v.push_back(p1);
        ++cnt;
    }
    if (lhs.contains(p2) && rhs.contains(p2)) {
        v.push_back(p2);
        ++cnt;
    }
    return cnt;
}

double solve(const double R, const vector<Point> &points);
int main() {
    int n;
    double R;
    vector<Point> points;
    // freopen("in", "r", stdin);

    while (scanf("%d", &n) > 0) {
        scanf("%lf", &R);
        int i;
        points.clear();
        asc(i, 1, n) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            points.push_back(Point{x, y});
        }
        double ans = solve(R, points);
        printf("%.2lf\n", ans);
    }
}

enum ObjType { LINE, ARC };
struct Obj {
    ObjType type;
    union {
        Line line;
        Arc arc;
    };
    Obj(const Line &l) : line(l) { type = LINE; }
    Obj(const Arc &a) : arc(a) { type = ARC; }
};

double solve(const double R, const vector<Point> &points) {
#ifdef NGDBG
    cout << R << endl;
    for (auto &p : points) {
        cout << p << endl;
    }
#endif

    vector<Obj> objects;
    objects.emplace_back(Line{points[0], points[1]}.upper_parallel(R));

    int i, j;

    rng(i, 2, int(points.size())) {
        const Line ul = Line{points[i - 1], points[i]}.upper_parallel(R);
        const Arc arc = Arc{points[i - 1], objects.back().line.p2, ul.p1, R};

#ifdef NGDBG
        cout << "pending objects: " << arc << ", " << ul << endl;
#endif

        vector<pair<int, Point>> v1, v2;
        rng(j, 0, int(objects.size())) {
            Obj &obj = objects[j];
            vector<Point> v;
            if (obj.type == LINE) {
                intersection(v, arc, obj.line);
            } else {
                intersection(v, arc, obj.arc);
            }
            for (auto &p : v) {
                v1.push_back(make_pair(j, p));
            }
        }

        sort(v1.begin(), v1.end(),
             [arc](const pair<int, Point> &a, const pair<int, Point> &b) {
                 return arc.angle(a.second) < arc.angle(b.second);
             });

#ifdef NGDBG
        cout << "arc intersection:" << endl;
        for (auto &pr : v1) {
            cout << pr.first << " - " << pr.second << endl;
        }
#endif

        rng(j, 0, int(objects.size())) {
            Obj &obj = objects[j];
            vector<Point> v;
            if (obj.type == LINE) {
                intersection(v, ul, obj.line);
            } else {
                intersection(v, ul, obj.arc);
            }
            for (auto &p : v) {
                v2.push_back(make_pair(j, p));
            }
        }
        sort(v2.begin(), v2.end(),
             [ul](const pair<int, Point> &a, const pair<int, Point> &b) {
                 return ul.length(a.second) < ul.length(b.second);
             });

#ifdef NGDBG
        cout << "line intersection:" << endl;
        for (auto &pr : v2) {
            cout << pr.first << " - " << pr.second << endl;
        }
#endif

        if (v2.size()) {
            pair<int, Point> &pr = v2.back();
            int j = pr.first;
            Obj obj = objects[j];
            objects.erase(objects.begin() + j, objects.end());
            if (obj.type == LINE) {
                obj.line.p2 = pr.second;
            } else {
                obj.arc.p2 = pr.second;
            }
            Line l = {pr.second, ul.p2};
            objects.push_back(obj);
            objects.emplace_back(l);
        } else {
            if (v1.size() == 0) {
                v1.push_back(make_pair(objects.size() - 1, arc.p1));
            }
            pair<int, Point> &pr = v1.back();
#ifdef NGDBG
            cout << "intersection at arc: " << pr.first << " - " << pr.second
                 << endl;
#endif
            int j = pr.first;
            Obj obj = objects[j];
            objects.erase(objects.begin() + j, objects.end());
            if (obj.type == LINE) {
                obj.line.p2 = pr.second;
            } else {
                obj.arc.p2 = pr.second;
            }
            Arc a = arc;
            a.p1 = pr.second;
            objects.push_back(obj);
            objects.emplace_back(a);
            objects.emplace_back(ul);
        }
#ifdef NGDBG
        cout << "objects:" << endl;
        for (auto &obj : objects) {
            if (obj.type == LINE) {
                cout << obj.line << endl;
            } else {
                cout << obj.arc << endl;
            }
        }
        cout << endl;
#endif
    }

#ifdef NGDBG
    cout << "calculate object total length" << endl;
#endif
    double ans = 0;
    for (auto &obj : objects) {
        double delta = 0;
        if (obj.type == LINE) {
            delta = obj.line.length();
#ifdef NGDBG
            cout << obj.line << endl;
#endif
        } else {
            delta = obj.arc.length();
#ifdef NGDBG
            cout << obj.arc << endl;
#endif
        }
#ifdef NGDBG
        cout << "length = " << delta << endl;
#endif
        ans += delta;
    }

    return ans;
}