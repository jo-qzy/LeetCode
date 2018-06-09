/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		//详解见25题的github网址
		//25题网址：https://github.com/jo-qzy/LeetCode/blob/master/25.ReverseNodesInK-Group.cpp
		ListNode* prev = NULL, *cur = head, *next = NULL;
		ListNode* ret = head;
		ListNode* cur_end = NULL, *prev_end = NULL;
		int count;
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		while (cur != NULL && cur->next != NULL)
		{
			count = 2;
			prev_end = cur_end;
			cur_end = cur;
			while (count--)
			{
				next = cur->next;
				cur->next = prev;
				prev = cur;
				cur = next;
			}
			if (prev_end == NULL)
			{
				ret = prev;
			}
			else
			{
				prev_end->next = prev;
			}
			prev = NULL;
		}
		cur_end->next = cur;
		return ret;
	}
};
