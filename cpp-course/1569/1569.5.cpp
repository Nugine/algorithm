#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

const double EPS = 1e-7;

struct Point {
    double x, y;
    friend ostream &operator<<(ostream &o, const Point &p) {
        return o << "Point(" << p.x << ", " << p.y << ")";
    }
    Point polar(const double r, const double angle) const {
        return {x + r * cos(angle), y + r * sin(angle)};
    }
    bool is_equal(const Point &rhs) const {
        return abs(x - rhs.x) < EPS && abs(y - rhs.y) < EPS;
    }
};

struct Vector {
    double x, y;
    friend ostream &operator<<(ostream &o, const Vector &v) {
        return o << "Vec(" << v.x << ", " << v.y << ')';
    }
    Vector(const double x, const double y) : x(x), y(y) {}
    Vector(const Point &p1, const Point &p2) : x(p2.x - p1.x), y(p2.y - p1.y) {}
    double cross(const Vector &rhs) const { return x * rhs.y - rhs.x * y; }
    double dot(const Vector &rhs) const { return x * rhs.x + y * rhs.y; }
    double angle(void) const { return atan2(y, x); }
    double length(void) const { return sqrt(x * x + y * y); }
    Vector rotated(const double angle) const {
        double cosA = cos(angle), sinA = sin(angle);
        return {cosA * x - sinA * y, sinA * x + cosA * y};
    }
};

Vector operator*(const Vector &v, const double r) { return {v.x * r, v.y * r}; }
Point operator+(const Vector &v, const Point &p) {
    return {p.x + v.x, p.y + v.y};
}
Point operator+(const Point &p, const Vector &v) {
    return {p.x + v.x, p.y + v.y};
}

struct Segment {
    Point p1, p2;
    friend ostream &operator<<(ostream &o, const Segment &l) {
        return o << "Segment{ " << l.p1 << ", " << l.p2 << " }";
    }
    Vector to_vector(void) const { return Vector(p1, p2); }
    double length(void) const { return Vector(p1, p2).length(); }
    double length(const Point &p) const { return Vector(p1, p).length(); }
    bool contains(const Point &p) const {
        Vector v1(p1, p2), v2(p1, p);
        double l1 = v1.length(), l2 = v2.length();
        return l2 <= l1 && abs(v1.dot(v2) - l1 * l2) < EPS;
    }
    Segment upper_parallel(const double distance) const {
        double k = (p2.y - p1.y) / (p2.x - p1.x);
        double theta = atan(abs(k));
        double dy = distance * cos(theta), dx = distance * sin(theta);
        double sign = (k > 0) ? (-1) : (1);
        return {{p1.x + sign * dx, p1.y + dy}, {p2.x + sign * dx, p2.y + dy}};
    }
};

struct Arc {
    Point o, p1, p2;
    double r;
    friend ostream &operator<<(ostream &o, const Arc &a) {
        return o << "Arc{ " << a.o << ", " << a.p1 << ", " << a.p2 << ", "
                 << a.r << " }";
    }
    double angle(const Point &p) const {
        double a1 = Vector(o, p1).angle(), a2 = Vector(o, p2).angle();
        double a = Vector(o, p).angle();
        return (a1 - a) + double(a1 < a2) * (M_PI * 2);
    }
    double length(void) const {
        double a1 = Vector(o, p1).angle(), a2 = Vector(o, p2).angle();
        return r * ((a1 - a2) + double(a1 < a2) * (M_PI * 2));
    }
    // do not check radius
    bool contains(const Point &p) const {
        double a1 = Vector(o, p1).angle(), a2 = Vector(o, p2).angle();
        double a = Vector(o, p).angle();
        if (a1 >= a2) {
            return a <= a1 && a >= a2;
        } else {
            return a <= a1 || a >= a2;
        }
    }
};

vector<Point> intersection(const Segment &lhs, const Segment &rhs) {
    const Point &p1 = lhs.p1, &p2 = lhs.p2;
    const Point &q1 = rhs.p1, &q2 = rhs.p2;

    const bool test1 = min(p1.x, p2.x) <= max(q1.x, q2.x) &&
                       min(q1.x, q2.x) <= max(p1.x, p2.x) &&
                       min(p1.y, p2.y) <= max(q1.y, q2.y) &&
                       min(q1.y, q2.y) <= max(p1.y, p2.y);
    if (!test1) {
        return {};
    }

    const Vector v1(q1, p1), v2(q1, p2), v3(q1, q2);
    const Vector v4(p1, q1), v5(p1, q2), v6(p1, p2);
    const bool test2 =
        v1.cross(v3) * v2.cross(v3) < 0 && v4.cross(v6) * v5.cross(v6) < 0;
    if (!test2) {
        return {};
    }

    const Vector &base = v3;
    const double d1 = abs(base.cross(Vector(p1, q1)));
    const double d2 = abs(base.cross(Vector(p2, q1)));
    const double t = d1 / (d1 + d2);
    return {p1 + v6 * t};
}

vector<Point> intersection(const Arc &lhs, const Segment &rhs) {
    const double angle = rhs.to_vector().angle();
    const Vector v1(lhs.o, rhs.p1), v2(lhs.o, rhs.p2);
    const Vector v3 = v1.rotated(-angle);
    const double y = v3.y;
    if (y > lhs.r || y < -lhs.r) {
        return {};
    }
    const double x = sqrt(lhs.r * lhs.r - y * y);
    const Point p1 = lhs.o + Vector(x, y).rotated(angle);
    const Point p2 = lhs.o + Vector(-x, y).rotated(angle);

    vector<Point> ans;
    if (lhs.contains(p1) && rhs.contains(p1)) {
        ans.push_back(p1);
    }
    if (!p1.is_equal(p2) && lhs.contains(p2) && rhs.contains(p2)) {
        ans.push_back(p2);
    }
    return ans;
}

vector<Point> intersection(const Segment &lhs, const Arc &rhs) {
    return intersection(rhs, lhs);
}

vector<Point> intersection(const Arc &lhs, const Arc &rhs) {
    const Vector v(lhs.o, rhs.o);
    const double d = v.length();
    if (d > lhs.r + rhs.r) {
        return {};
    }
    const double delta =
        acos((lhs.r * lhs.r + d * d - rhs.r * rhs.r) / (2 * lhs.r * d));
    const double angle = v.angle();
    const Point p1 = lhs.o.polar(lhs.r, angle + delta);
    const Point p2 = lhs.o.polar(lhs.r, angle - delta);

    vector<Point> ans;
    if (lhs.contains(p1) && rhs.contains(p1)) {
        ans.push_back(p1);
    }
    if (!p1.is_equal(p2) && lhs.contains(p2) && rhs.contains(p2)) {
        ans.push_back(p2);
    }
    return ans;
}

enum ObjType { SEGMENT, ARC };
struct Object {
    ObjType type;
    union {
        Segment seg;
        Arc arc;
    };
    Object(const Segment &s) : seg(s) { type = SEGMENT; }
    Object(const Arc &a) : arc(a) { type = ARC; }
};

double solve(const double R, const vector<Point> &points) {
    vector<Object> objects;
    objects.emplace_back(Segment{points[0], points[1]}.upper_parallel(R));
    int i, j;
    rng(i, 2, int(points.size())) {
        const Segment us = Segment{points[i - 1], points[i]}.upper_parallel(R);
        const Arc arc = Arc{points[i - 1], objects.back().seg.p2, us.p1, R};
        vector<pair<int, Point>> v1, v2;
        rng(j, 0, int(objects.size())) {
            const Object &obj = objects[j];
            vector<Point> v;
            if (obj.type == SEGMENT) {
                v = intersection(arc, obj.seg);
            } else {
                v = intersection(arc, obj.arc);
            }
            for (auto &p : v) {
                v1.push_back(make_pair(j, p));
            }
        }
        sort(v1.begin(), v1.end(),
             [arc](const pair<int, Point> &a, const pair<int, Point> &b) {
                 return arc.angle(a.second) < arc.angle(b.second);
             });

        rng(j, 0, int(objects.size())) {
            const Object &obj = objects[j];
            vector<Point> v;
            if (obj.type == SEGMENT) {
                v = intersection(us, obj.seg);
            } else {
                v = intersection(us, obj.arc);
            }
            for (auto &p : v) {
                v2.push_back(make_pair(j, p));
            }
        }
        sort(v2.begin(), v2.end(),
             [us](const pair<int, Point> &a, const pair<int, Point> &b) {
                 return us.length(a.second) < us.length(b.second);
             });

        if (v2.size()) {
            const pair<int, Point> &pr = v2.back();
            const int j = pr.first;
            Object obj = objects[j];
            objects.erase(objects.begin() + j, objects.end());
            if (obj.type == SEGMENT) {
                obj.seg.p2 = pr.second;
            } else {
                obj.arc.p2 = pr.second;
            }
            const Segment s = {pr.second, us.p2};
            objects.push_back(obj);
            objects.emplace_back(s);
        } else {
            if (v1.size() == 0) {
                v1.push_back(make_pair(objects.size() - 1, arc.p1));
            }
            const pair<int, Point> &pr = v1.back();
            const int j = pr.first;
            Object obj = objects[j];
            objects.erase(objects.begin() + j, objects.end());
            if (obj.type == SEGMENT) {
                obj.seg.p2 = pr.second;
            } else {
                obj.arc.p2 = pr.second;
            }
            const Arc a = {arc.o, pr.second, arc.p2, arc.r};
            objects.push_back(obj);
            objects.emplace_back(a);
            objects.emplace_back(us);
        }
    }

    double ans = 0;
    for (auto &obj : objects) {
        double delta = 0;
        if (obj.type == SEGMENT) {
            delta = obj.seg.length();
        } else {
            delta = obj.arc.length();
        }
        ans += delta;
    }
    return ans;
}

int main() {
    int n;
    while (cin >> n) {
        double R;
        vector<Point> points;
        cin >> R;
        int i;
        rng(i, 0, n) {
            double x, y;
            cin >> x >> y;
            points.push_back(Point{x, y});
        }
        const double ans = solve(R, points);
        printf("%.2lf\n", ans);
    }
}
