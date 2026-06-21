/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        TreeNode *z = root;
        TreeNode *y = nullptr;
        while (z) {
            y = z;
            if (z->val >= val) {
                z = z->left;
            } else z = z->right;
        }
        if (y->val >= val) {
            y->left = new TreeNode(val);
        }
        else {
            y->right = new TreeNode(val);
        }

        return root;
    }
};