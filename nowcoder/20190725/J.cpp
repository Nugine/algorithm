#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pd(x) printf("%d", (x))
#define pdsp(x) printf("%d ", (x))
#define sppd(x) printf(" %d", (x))
#define pdln(x) printf("%d\n", (x))

struct Node {
    Node *prev;
    Node *next;
    string key;
    int val;
};

class LinkedHashMap {
  public:
    unordered_map<string, Node *> map;
    Node *head;
    Node *tail;
    int len;
    int cap;

    LinkedHashMap(int cap) {
        head = new Node{NULL, NULL, "", 0};
        tail = head;
        len = 0;
        this->cap = cap;
    }

    int access(const char *key_buf, int val) {
        string key(key_buf);

        int ans;
        auto it = map.find(key);
        if (it == map.end()) {
            Node *nd_ptr = new Node{tail, NULL, key, val};
            map.emplace(key, nd_ptr);
            tail->next = nd_ptr;
            tail = nd_ptr;
            ++len;
            ans = val;
        } else {
            Node *nd = it->second;
            if (nd != tail) {
                Node *pr = nd->prev;
                Node *ne = nd->next;
                if (pr != NULL) {
                    pr->next = ne;
                }
                if (ne != NULL) {
                    ne->prev = pr;
                }
                nd->prev = tail;
                nd->next = NULL;
                tail->next = nd;
                tail = nd;
            }
            ans = nd->val;
        }

        if (len > cap) {
            Node *nd = head->next;
            Node *pr = nd->prev;
            Node *ne = nd->next;
            if (pr != NULL) {
                pr->next = ne;
            }
            if (ne != NULL) {
                ne->prev = pr;
            }
            map.erase(nd->key);
            --len;
        }
        return ans;
    }

    bool ask(const char *key_buf, int offset, int &ans) {
        string key(key_buf);

        auto it = map.find(key);
        if (it == map.end()) {
            return false;
        } else {
            Node *nd = it->second;
            Node *ptr = NULL;
            if (offset == -1) {
                ptr = nd->prev;
            } else if (offset == 1) {
                ptr = nd->next;
            } else {
                ptr = nd;
            }
            if (ptr == NULL || ptr == head) {
                return false;
            }
            ans = ptr->val;
            return true;
        }
    }
};

void solve();
int main() {
    int T;
    rd(T);
    while (T--) {
        solve();
    }
    return 0;
}

void solve() {
    int Q, M;
    rd2(Q, M);
    LinkedHashMap lkmap(M);

    while (Q--) {
        int opt;
        char buf[20];
        int v;
        scanf("%d%s%d", &opt, buf, &v);

        if (opt == 0) {
            int ans = lkmap.access(buf, v);
            printf("%d\n", ans);
        } else if (opt == 1) {
            int ans;
            bool is_valid = lkmap.ask(buf, v, ans);
            if (is_valid) {
                printf("%d\n", ans);
            } else {
                printf("Invalid\n");
            }
        }
    }
}