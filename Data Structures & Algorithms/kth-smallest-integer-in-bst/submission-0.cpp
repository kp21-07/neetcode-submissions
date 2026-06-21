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
    void count(TreeNode *x, int &c, int k, int &ans) {
        if (x == NULL) return;
        count(x->left, c, k, ans);
        c++;
        if (c == k) {
            ans = x->val;
            return;
        }
        count(x->right, c, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int c = 0;
        count(root, c, k, ans);
        return ans;
    }
};