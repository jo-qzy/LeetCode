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
		getSequence(p, pa);//得到p的前序
		getSequence(q, qa);//得到q的前序
		//比较序列
		if (pa.size() != qa.size())
		{
			return false;
		}
		for (int i = 0; i < pa.size(); i++)
		{
			if (pa[i] && qa[i])
			{
				if (pa[i]->val != qa[i]->val)
				{
					return false;
				}
			}
			else if (pa[i] || qa[i])
			{
				return false;
			}
		}
		return true;
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