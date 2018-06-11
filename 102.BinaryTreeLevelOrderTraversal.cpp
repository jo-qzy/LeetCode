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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == NULL)
		{
			//特殊情况特殊处理
			return ret;
		}
		queue<TreeNode*> q;
		vector<int> tmp;
		TreeNode* cur = NULL;
		q.push(root);
		int count = 1;//根节点个数为1个
		while (q.empty() != true)
		{
			//每次出队列一个节点，将节点的val存入临时数组
			cur = q.front();
			tmp.push_back(cur->val);
			count--;//当前层节点个数减1
			q.pop();
			//入队左右节点
			if (cur->left)
			{
				q.push(cur->left);
			}
			if (cur->right)
			{
				q.push(cur->right);
			}
			if (count == 0)
			{
				//如果当前层节点已经全部记录，节点数重置为队列的size
				//队列的size就是下一层节点的个数
				count = q.size();
				ret.push_back(tmp);//存储临时数组
				tmp.clear();//清空临时数组
			}
		}
		return ret;
	}
};