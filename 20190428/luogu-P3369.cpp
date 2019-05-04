// treap

#include <algorithm>
#include <cstdio>
using namespace std;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define pdln(x) printf("%d\n", (x))

struct Node {
    int key; // 随机键值
    int val; // 实际数值

    int size; // 以该节点为根的树的结点数
    int same; // 该结点保存的相同数值的个数

    Node *left, *right;
};

inline void update_size(Node *const nd) {
    nd->size = nd->same;
    if (nd->left) {
        nd->size += nd->left->size;
    }
    if (nd->right) {
        nd->size += nd->right->size;
    }
}

inline int rand() {
    static int seed = 19260817;
    return seed = seed * 482711LL % 2147483647;
}

void rotate_right(Node *&nd) {
    if (nd->left == NULL) {
        return;
    }
    Node *ld = nd->left;
    nd->left = ld->right;
    ld->right = nd;
    update_size(nd);
    update_size(ld);
    nd = ld;
}

void rotate_left(Node *&nd) {
    if (nd->right == NULL) {
        return;
    }
    Node *rd = nd->right;
    nd->right = rd->left;
    rd->left = nd;
    update_size(nd);
    update_size(rd);
    nd = rd;
}

inline Node *new_node(const int val) {
    return new Node{rand(), val, 1, 1, NULL, NULL};
}

inline void delete_node(Node *&nd, Node *const p = NULL) {
    delete nd;
    nd = p;
}

// static Node _node_pool[100000 + 7];
// static Node *tail = _node_pool + 1;

// inline Node *new_node(const int val) {
//     Node *nd = tail++;
//     nd->key = rand();
//     nd->val = val;
//     nd->same = nd->size = 1;
//     nd->left = nd->right = NULL;
//     return nd;
// }

// inline void delete_node(Node *&nd, Node *const p = NULL) {
//     *nd = *(--tail);
//     nd = p;
// }

void insert(Node *&nd, const int x) {
    if (nd == NULL) {
        nd = new_node(x);
        return;
    }
    if (x < nd->val) {
        insert(nd->left, x);
        if (nd->left->key < nd->key) {
            rotate_right(nd);
        }
    } else if (x > nd->val) {
        insert(nd->right, x);
        if (nd->right->key < nd->key) {
            rotate_left(nd);
        }
    } else {
        ++nd->same;
    }
    update_size(nd);
}

void remove(Node *&nd, const int x) {
    if (nd == NULL) {
        return;
    }

    if (x < nd->val) {
        remove(nd->left, x);
        update_size(nd);
    } else if (x > nd->val) {
        remove(nd->right, x);
        update_size(nd);
    } else {
        if (nd->same > 1) {
            --nd->same;
            --nd->size;
        } else {
            if (nd->left == NULL && nd->right == NULL) {
                delete_node(nd);
            } else if (nd->left == NULL) {
                delete_node(nd, nd->right);
            } else if (nd->right == NULL) {
                delete_node(nd, nd->left);
            } else {
                if (nd->left->key < nd->right->key) {
                    rotate_right(nd);
                    remove(nd->right, x);
                    update_size(nd);
                } else {
                    rotate_left(nd);
                    remove(nd->left, x);
                    update_size(nd);
                }
            }
        }
    }
}

int query_rank(const Node *const nd, const int x) {
    if (nd == NULL) {
        return 0;
    }

    if (nd->val == x) {
        return 1 + ((nd->left) ? (nd->left->size) : 0);
    }

    if (x < nd->val) {
        return query_rank(nd->left, x);
    } else {
        return query_rank(nd->right, x) + nd->same +
               ((nd->left) ? (nd->left->size) : 0);
    }
}

int kth(const Node *const nd, const int k) {
    if (nd == NULL || k < 0 || k > nd->size) {
        return 0;
    }
    int t = (nd->left) ? (nd->left->size) : 0;

    if (k >= t + 1 && k <= nd->same + t) {
        return nd->val;
    }
    if (t >= k) {
        return kth(nd->left, k);
    } else {
        return kth(nd->right, k - t - nd->same);
    }
}

bool query_pre(const Node *const nd, const int x, int &ans) {
    if (nd == NULL) {
        return false;
    }
    if (x > nd->val) {
        ans = nd->val;
        query_pre(nd->right, x, ans);
        return true;
    } else {
        return query_pre(nd->left, x, ans);
    }
}

bool query_post(const Node *const nd, const int x, int &ans) {
    if (nd == NULL) {
        return false;
    }
    if (x < nd->val) {
        ans = nd->val;
        query_post(nd->left, x, ans);
        return true;
    } else {
        return query_post(nd->right, x, ans);
    }
}

int main() {
    Node *root = NULL;

    int n;
    rd(n);
    int i;
    asc(i, 1, n) {
        int opt, x;
        rd2(opt, x);

        int ans;
        switch (opt) {
        case 1:
            insert(root, x);
            break;

        case 2:
            remove(root, x);
            break;

        case 3:
            ans = query_rank(root, x);
            pdln(ans);
            break;

        case 4:
            ans = kth(root, x);
            pdln(ans);
            break;

        case 5:
            query_pre(root, x, ans);
            pdln(ans);
            break;

        case 6:
            query_post(root, x, ans);
            pdln(ans);
            break;

        default:
            break;
        }
    }

    return 0;
}