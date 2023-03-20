
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// 给定的两个节点一个为 p，一个为 q
// 当前节点记为 cur，他的左子树记为 left，他的右子树记为 right
// 我们需要 left 和 right 的值来做逻辑判断，因此很适合用后序遍历。
// 1. 左右子树在遍历的过程中，如果遇到 p 或者 q 或者 null，直接返回 p 或者 q 或者 null
// 2. 左右子树都返回 null，则说明 cur 的整颗树上都没有发现 p 或者 q，返回 null
// 3. 左右子树都返回不为空，则说明 cur 的树上发现了 p 或者 q。cur 就是公共祖先节点
// 4. 左右子树有一个返回不为空，要么发现了 p 或者 q，要么 cur 已经是最近的公共祖先节点，直接返回 cur 即可


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        return left != nullptr ? left : right;
    }
};

