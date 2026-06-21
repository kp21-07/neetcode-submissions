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
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);   
    }

    bool valid(TreeNode *x, long long mini, long long maxi) {
        if (x == NULL) return true;

        if (x->val <= mini || x->val >= maxi) return false;

        return valid(x->left, mini, x->val) && valid(x->right, x->val, maxi);
    }
};