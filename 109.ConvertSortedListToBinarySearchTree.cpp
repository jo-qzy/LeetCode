/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
	TreeNode* sortedListToBST(ListNode* head) {
		TreeNode* ret = NULL;
		//convert是递归函数，需要传入的参数为当前节点的
		convert(&ret, head, NULL);
		return ret;
	}
private:
	void convert(TreeNode** root, ListNode* head, ListNode* tail)
	{
		if (head == tail)
		{
			*root = NULL;
			return;
		}
		//找中间节点，记录
		ListNode* middle = findMiddleListNode(head, tail);
		//当前树节点分配空间并初始化为middle的值
		*root = new TreeNode(middle->val);
		//递归左右
		convert(&(*root)->left, head, middle);
		convert(&(*root)->right, middle->next, tail);
	}

	ListNode* findMiddleListNode(ListNode* head, ListNode* end)
	{
		//找中间节点
		if (head == end)
		{
			return NULL;
		}
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != end && fast->next != end)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};