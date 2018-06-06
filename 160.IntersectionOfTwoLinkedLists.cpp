/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//两种方法：
		//1.找到两个尾节点，若相同，相交，长的链表先走相差的步数，两者同时走找交点
		//2.同样的找尾指针，若相同，相交，将尾连任意表的头构成环，转换成求环入口问题
		//此种方法为第一种，第二种在下面
        int len1 = 0, len2 = 0;
		int diff = 0;
		ListNode * cur1 = headA, *cur2 = headB;
		if (cur1 == NULL || cur2 == NULL)
		{
			//这里允许传入空链表，那就特殊处理
			//在我的链表面试题中我是直接assert掉空的情况的
			return NULL;
		}
		//先找尾
		while (cur1->next)
		{
			len1++;
			cur1 = cur1->next;
		}
		while (cur2->next)
		{
			len2++;
			cur2 = cur2->next;
		}
		//尾相同，有戏，说明相交，不相交直接返回空
		if (cur1 != cur2)
		{
			return NULL;
		}
		//把长的链表给cur1，短的给cur2
		if (len1 < len2)
		{
			cur1 = headB, cur2 = headA;
			diff = len2 - len1;
		}
		else
		{
			cur1 = headA, cur2 = headB;
			diff = len1 - len2;
		}
		//长链表先走相差的步数
		while (diff--)
		{
			cur1 = cur1->next;
		}
		//两个链表同时走，当相遇之时便是目标节点
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
    }
};


class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode * cur1 = headA, *cur2 = headB;
		ListNode * tmp = NULL;
		if (cur1 == NULL || cur2 == NULL)
		{
			//这里允许传入空链表，那就特殊处理
			//在我的链表面试题中我是直接assert掉空的情况的
			return NULL;
		}
		//先找尾
		while (cur1->next)
		{
			cur1 = cur1->next;
		}
		while (cur2->next)
		{
			cur2 = cur2->next;
		}
		if (cur1 != cur2)
		{
			return NULL;
		}
		tmp = cur1;//由于不允许修改结构，先链成环等会断开
		cur1->next = headB;
		cur1 = cur2 = headA;
		//找到相遇点
		do
		{
			cur1 = cur1->next;
			cur2 = cur2->next->next;
		}while(cur1 != cur2);
		//cur1重新置为首节点，cur2为相遇点，同时走，再次相遇即环入口
		cur1 = headA;
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		//断开链表，因为测试中不允许修改结构
		tmp->next = NULL;
		return cur1;
	}
};