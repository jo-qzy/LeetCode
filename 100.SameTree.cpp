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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pa, qa;
        getSequence(p, pa);
        getSequence(q, qa);
        if (pa.size() != qa.size())
        {
            return false;
        }
        for(int i = pa.size())
    }
    
private:
    void getSequence(TreeNode* root, vector<TreeNode*>& a)
    {
        a.push_back(root);
        if (root == NULL)
        {
            return;
        }
        getSequence(root->left, a);
        getSequence(root->right, a);
    }
};