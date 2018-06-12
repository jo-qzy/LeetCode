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
	ListNode* partition(ListNode* head, int x) {
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* next = NULL;
		ListNode* slow_prev = NULL;
		ListNode* fast_prev = NULL;
		while (slow != NULL)
		{
			//从slow开始往后找符合要求的节点
			fast = slow;
			while (fast && fast->val >= x)
			{
				fast_prev = fast;
				fast = fast->next;
			}
			//找到了，分三种情况
			//1.slow就是目标节点，那就不交换，slow后走
			//2.slow是头结点，fast不和slow重合，那就需要更改头结点，特殊处理一下
			//3.slow和fast不重合，也不属于上面两种情况，那就移动fast节点到slow前面
			if (fast)
			{
				//情况1
				if (fast == slow)
				{
					slow_prev = slow;
					slow = slow->next;
					continue;
				}
				else
				{
					fast_prev->next = fast->next;
					fast->next = slow;
					if (slow == head)
					{
						//情况2
						head = fast;
						slow_prev = head;
					}
					else
					{
						//情况3
						slow_prev->next = fast;
						slow_prev = fast;
					}
				}
			}
			else
			{
				return head;
			}
		}
		return head;
	}
};