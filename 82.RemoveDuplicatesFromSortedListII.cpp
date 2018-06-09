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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			//国际惯例，特殊情况特殊处理
			return head;
		}
		ListNode * cur = head;
		ListNode * next = NULL;
		ListNode * prev = NULL;
		ListNode * ret = head;
		while (cur != NULL && cur->next != NULL)
		{
			//如果值没有出现重复的，直接找下一个
			if (cur->val != cur->next->val)
			{
				prev = cur;
				cur = cur->next;
				continue;
			}
			//走到此处说明有重复值出现，开始删除
			int tmp_val = cur->val;//记录下当前要删除的值
			while (cur && cur->val == tmp_val)
			{
				//一直删除和目标值相同的节点
				next = cur->next;
				free(cur);
				cur = cur->next;
			}
			//删除后链表会变成两段，断开是因为中间删除了元素
			//删除完毕后cur指向的是后面一段非目标值的第一个节点，需要和前面的链表链上
			if (prev == NULL)
			{
				//当prev为空说明删除的是第一个，需要改变返回值
				ret = cur;
			}
			else
			{
				//链接前后两段链表
				prev->next = cur;
			}
		}
		return ret;
	}
};
