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
	bool isSubtree(TreeNode* s, TreeNode* t) {
		bool result = false;
		//递归找s树中和t根节点值一样的节点
		if (s != NULL && t != NULL)
		{
			if (s->val == t->val)
				result = judgeSubtree(s, t);
			if (result == false)
				result = isSubtree(s->left, t);
			if (result == false)
				result = isSubtree(s->right, t);
		}
		return result;
	}
private:
	bool judgeSubtree(TreeNode* s, TreeNode* t)
	{
		//找到相同节点就进入函数判断，其他节点是否相同
		if (t == NULL)
			return true;
		if (s == NULL)
			return false;
		if (s->val != t->val)
			return false;
		//限定条件，t树在s中存在，但是s的子树最下层还有别的子节点，所以限定
		if ((s->left != NULL && t->left == NULL) || (s->right != NULL && t->right == NULL))
			return false;
		return judgeSubtree(s->left, t->left) && judgeSubtree(s->right, t->right);
	}
};