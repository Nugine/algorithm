// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

struct Frame {
    int state;
    TreeNode *root;
};

class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<Frame> frames;
        vector<int> out;
        frames.push_back(Frame{0, root});

        while (!frames.empty()) {
            auto &f = frames.back();
            if (f.state == 0) {
                if (f.root == nullptr) {
                    frames.pop_back();
                } else {
                    f.state = 1;
                    frames.push_back(Frame{
                        0,
                        f.root->left,
                    });
                }
            } else if (f.state == 1) {
                f.state = 2;
                frames.push_back(Frame{0, f.root->right});
            } else if (f.state == 2) {
                out.push_back(f.root->val);
                frames.pop_back();
            }
        }

        return out;
    }
};

int main() {
    TreeNode nodes[3];
    nodes[0] = TreeNode(1, nullptr, &nodes[1]);
    nodes[1] = TreeNode(2, &nodes[2], nullptr);
    nodes[2] = TreeNode(3, nullptr, nullptr);
    auto sol = Solution();
    auto ans = sol.postorderTraversal(&nodes[0]);
}