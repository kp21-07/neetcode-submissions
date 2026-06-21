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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};

        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> v;
        
        while(!q.empty()) {
            int n = q.size();
            TreeNode* end = NULL;
            while(n--) {
                end = q.front();
                q.pop();
                if (end->left != NULL) q.push(end->left);
                if (end->right != NULL) q.push(end->right);
            }
            v.push_back(end->val);
        }
        return v;
    }
};