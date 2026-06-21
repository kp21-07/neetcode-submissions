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
private:
    TreeNode* build(vector<int>& preorder, int pBegin, int pEnd,
                    vector<int>& inorder, int iBegin, int iEnd,
                    unordered_map<int, int>& inMp)
    {
        if (pBegin > pEnd || iBegin > iEnd) return NULL;

        int root_val = preorder[pBegin];
        int root_idx = inMp[root_val];
        int nums_left = root_idx - iBegin;

        return new TreeNode(root_val,
                            build(preorder, pBegin+1, pBegin+nums_left, inorder, iBegin, root_idx-1, inMp),
                            build(preorder, pBegin+1+nums_left, pEnd, inorder, root_idx+1, iEnd, inMp));
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) inMp[inorder[i]] = i;

        return build(preorder, 0, n-1, inorder, 0, n-1, inMp);
    }
};