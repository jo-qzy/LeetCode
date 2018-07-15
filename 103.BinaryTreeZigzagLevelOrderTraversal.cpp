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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		//层序遍历简单变形
		TreeNode* tail = root;
		TreeNode* tmp = NULL;
		TreeNode* cur = root;
		int flag = 0;
		vector<vector<int>> ret;
		vector<int> cur_level;
		queue<TreeNode*> level_order;
		if (root != NULL)
		{
			level_order.push(root);
		}
		//层序遍历
		while (level_order.empty() == false)
		{
			cur = level_order.front();
			level_order.pop();
			cur_level.push_back(cur->val);
			//左节点有效入队，右节点有效入队
			if (cur->left != NULL)
			{
				level_order.push(cur->left);
				tmp = cur->left;//记录一层最后一个节点
			}
			if (cur->right != NULL)
			{
				level_order.push(cur->right);
				tmp = cur->right;
			}
			if (cur == tail)
			{
				if (flag == 0)
				{
					flag = 1;
				}
				else
				{
					//需要逆转成从右往左
					int left = 0, right = cur_level.size() - 1;
					while (left < right)
					{
						cur_level[right] ^= cur_level[left];
						cur_level[left] ^= cur_level[right];
						cur_level[right] ^= cur_level[left];
						left++, right--;
					}
					flag = 0;
				}
				//将当前层存储，并清空临时的数组
				ret.push_back(cur_level);
				cur_level.clear();
				tail = tmp;//更新尾结点
			}
		}
		return ret;
	}
};