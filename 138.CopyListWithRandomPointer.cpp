/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return NULL;
		RandomListNode* cur = head;
		RandomListNode* next = NULL;
		//在每个节点后面创建一个值相同的节点
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = new RandomListNode(cur->label);
			cur->next->next = next;
			cur = next;
		}
		cur = head;
		RandomListNode* ret_head = head->next;
		//由于新复制的节点和原节点random指针指向的相对位置是相同的
		//所以cur节点的random不为空时，next->random应当指向cur->random->next
		//注意这里不能一边处理random一边断开链表
		//如果后面的节点random指针指向前面断开的节点，那就会出问题
		//第一次搞了将近半个小时卡在这，吃了亏，面试不注意就凉了
		while (cur != NULL)
		{
			next = cur->next;
			if (cur->random != NULL)
				next->random = cur->random->next;
			cur = next->next;
		}
		//最后才分离两个链表，返回新链表的头
		cur = head;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = next->next;
			if (next->next != NULL)
				next->next = next->next->next;
			cur = cur->next;
		}
		return ret_head;
	}
};