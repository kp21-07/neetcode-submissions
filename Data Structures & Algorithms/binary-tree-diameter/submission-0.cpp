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
    int update(TreeNode* root, int* maxDia) {
        if (!root) return 0;

        int left = update(root->left, maxDia);
        int right = update(root->right, maxDia);

        *maxDia = max(*maxDia, left+right);
        
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        update(root, &maxDia);
        return maxDia;
    }
};