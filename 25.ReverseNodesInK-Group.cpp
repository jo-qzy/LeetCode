/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
bool JudgeNodeNum(struct ListNode* cur, int k)
{
	//得判断一下长度够不够翻转
	while (k--)
	{
		if (cur == NULL)
		{
			return false;
		}
		cur = cur->next;
	}
	return true;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode *prev = NULL, *cur = head, *next = NULL;
	struct ListNode* ret = head;
	struct ListNode *cur_end = NULL, *prev_end = NULL;
	int count = k;
    if (head == NULL || k == 1)
    {
		//翻转k为1或者为空，直接返回
        return ret;
    }
	while (JudgeNodeNum(cur, k) == true)
	{
		count = k;
		prev_end = cur_end;//记录前一部分的尾结点
		cur_end = cur;//记录当前尾结点
		while (count--)
		{
			//翻转当前部分的k个节点
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		if (ret == head)
		{
			//ret为返回的头结点
			ret = prev;
		}
		if (prev_end != NULL)
		{
			//如果前一个部分的k个节点的尾不为第一部分的尾
			//链接两个部分
			prev_end->next = prev;
		}
		prev = NULL;
	}
    if (cur_end != NULL)
    {
		//链接剩余部分
        cur_end->next = cur;        
    }
	return ret;
}