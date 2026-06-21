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
    int goodNodes(TreeNode* root) {
        return count(root, root->val);
    }
private:
    int count(TreeNode *x, int maxi) {
        if (x == nullptr) return 0;

        int c = 0;
        
        if (x->val >= maxi) c = 1;
        maxi = max(maxi, x->val);

        c += count(x->left, maxi);
        c += count(x->right, maxi);

        return c;
    }
};