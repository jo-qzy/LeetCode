/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	//要删除倒数第n个节点，有两种方式
	//常规方式，找到倒数第n + 1个节点
	//连接倒数n + 1和倒数n - 1，释放n
    int count = n + 1;
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	struct ListNode* dst = head;
	while (count--)
	{
		//快指针先走n + 1步
		if (fast == NULL)
		{
			//遇到传入n超过链表长度，直接删除头结点
			slow = slow->next;
			free(dst);
			return slow;
		}
		fast = fast->next;
	}
	while (fast != NULL)
	{
		//快慢指针一起走，当快指针指向NULL，慢指针即倒数第n + 1个节点
		slow = slow->next;
		fast = fast->next;
	}
	dst = slow->next;
	slow->next = slow->next->next;
	free(dst);//别忘记释放目标节点
	return head;
}