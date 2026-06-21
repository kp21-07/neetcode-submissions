/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* z = root;
        while(z != nullptr) {
            if (z->val < p->val && z->val < q->val) {
                z = z->right;
            }
            else if (z->val > p->val && z->val > q->val) {
                z = z->left;
            } else {
                return z;
            }
        }
        return nullptr;
    }
};