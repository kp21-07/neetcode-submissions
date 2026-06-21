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
    int getheight(TreeNode* x) {
        if (!x) return 0;
        return 1 + max(getheight(x->left), getheight(x->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = getheight(root->left);
        int right = getheight(root->right);
        if (abs(left-right) < 2) {
            if (isBalanced(root->left) && isBalanced(root->right)) return true;
            else return false;
        }
        else return false;
    }
};