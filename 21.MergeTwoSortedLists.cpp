/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* cur = NULL;
	struct ListNode* ret = NULL;
	//链表为空，特殊处理
	if (l1 == NULL)
	{
		return l2;
	}
	else if (l2 == NULL)
	{
		return l1;
	}
	//链表不为空，令ret指向两个链表中首个元素较小的链
	if (l1->val > l2->val)
	{
		ret = l2;
		l2 = l2->next;
	}
	else
	{
		ret = l1;
		l1 = l1->next;
	}
	cur = ret;
	while (l1 != NULL && l2 != NULL)
	{
		//小的节点链在cur后，cur往后移动
		if (l1->val > l2->val)
		{
			cur->next = l2;
			l2 = l2->next;
		}
		else
		{
			cur->next = l1;
			l1 = l1->next;
		}
		cur = cur->next;
	}
	//将剩余链表链上
	if (l1 == NULL)
	{
		cur->next = l2;
	}
	else
	{
		cur->next = l1;
	}
	return ret;
}
