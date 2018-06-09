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
	bool hasCycle(ListNode *head) {
		ListNode * fast = head, *slow = head;
		while (fast && fast->next)
		{
			//快指针走两步，慢指针走一步
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				fast = head;
				while (fast != slow)
				{
					//相遇点和从头开始走的指针同时走，走过的距离为链表长度的n倍
					//所以同时走相遇的位置就是入口
					slow = slow->next;
					fast = fast->next;
				}
				return fast;
			}
		}
		return NULL;
	}
};
