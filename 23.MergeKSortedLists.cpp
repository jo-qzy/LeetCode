//方法1
//这种方法应该是O(n^2)的时间复杂度
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = NULL;
		int i = 0;
		//找到第一个非空链表
		for (i; i < lists.size(); i++)
		{
			if (lists[i])
			{
				head = lists[i];
				break;
			}
		}
		if (lists.size() - i <= 1)
		{
			//如果只有一个非空链表或者全为空链表或者没有链表
			return head;
		}
		for (i = i + 1; i < lists.size(); i++)
		{
			//head指向一个非空链表
			if (lists[i])
			{
				//找到下一个非空链表，归并排序，形成新的链表
				head = mergeTwoLists(head, lists[i]);
			}
		}
		return head;
	}

private:
	ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
	{
		//两链表归并
		ListNode* head = NULL;
		ListNode* cur = NULL;
		if (head1->val < head2->val)
		{
			head = head1;
			head1 = head1->next;
		}
		else
		{
			head = head2;
			head2 = head2->next;
		}
		cur = head;
		while (head1 && head2)
		{
			if (head1->val < head2->val)
			{
				cur->next = head1;
				head1 = head1->next;
			}
			else
			{
				cur->next = head2;
				head2 = head2->next;
			}
			cur = cur->next;
		}
		if (head1)
		{
			cur->next = head1;
		}
		else
		{
			cur->next = head2;
		}
		return head;
	}
};

//方法2
//自己思路是第一种，看了网上的解法，这种是O(n*logn)
//无非是归并的时机不同，第一次归并次数为n/2
//第二次是n/4，第三次n/8，直至归并只剩一个链表
//所以为logn次，归并过程需要n的时间复杂度，所以时间复杂度为O(n*logn)
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution2 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
		{
			return NULL;
		}
		int left = 0;
		int right = lists.size() - 1;
		while (right != 0)
		{
			//归并第一个和倒数第一个，完成后放在第一个位置
			//第二个和倒数第二个归并，完成后放在第一个位置,直至归并完
			while (left < right)
			{
				lists[left] = mergeTwoLists(lists[left], lists[right]);
				left++, right--;
			}
			left = 0;
		}
		return lists[0];
	}

private:
	ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
	{
		if (head1 == NULL)
		{
			return head2;
		}
		if (head2 == NULL)
		{
			return head1;
		}
		ListNode* head = NULL;
		ListNode* cur = NULL;
		if (head1->val < head2->val)
		{
			head = head1;
			head1 = head1->next;
		}
		else
		{
			head = head2;
			head2 = head2->next;
		}
		cur = head;
		while (head1 && head2)
		{
			if (head1->val < head2->val)
			{
				cur->next = head1;
				head1 = head1->next;
			}
			else
			{
				cur->next = head2;
				head2 = head2->next;
			}
			cur = cur->next;
		}
		if (head1)
		{
			cur->next = head1;
		}
		else
		{
			cur->next = head2;
		}
		return head;
	}
};