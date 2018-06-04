/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//解法1
class Solution1 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode * cur = head, * prev = NULL;
        ListNode * ret = NULL;
        int length = 0;
        while (cur)
        {
			//需要先知道链表长度，才能进行旋转，先遍历一遍
            cur = cur->next;
            length++;
        }
		//旋转的k如果超过链表长度，其实等价于旋转k % length
        k = k % length;
        k = length - k;//倒数第k个就是正数lenth - k个
        cur = head;
        while (k--)
        {
			//走到倒数第k的位置
            prev = cur;
            cur = cur->next;
        }
		//如果cur为空为空，说明旋转的长度为length，也就不需要旋转
        if (cur != NULL)
        {
            ret = cur;//cur为新的头
            prev->next = NULL;
            while(cur->next != NULL)
            {
				//cur走到尾部，链接原来的头
                cur = cur->next;
            }
            cur->next = head;
        }
        return ret;
    }
};

//解法2
class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * ret = NULL;
        if (head == NULL)
        {
            return NULL;
        }
        ListNode * slow = head, * fast = head,* prev = NULL;
        int length = 0;
        while (k--)
        {
            fast = fast->next;
            length++;
            if (fast == NULL)
            {
				//当k很大的时候，我们已经知晓链表长度为length
				//只需要再走k % length步即可，提前结束循环
                k = k % length;
                fast = head;
            }
        }
        if (fast == head)
        {
			//fast指向头，不需要翻转
            return head;
        }
        while (fast)
        {
			//下面同解法1，链接两个部分
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        ret = slow;
        while (slow->next)
        {
            slow = slow->next;
        }
        slow->next = head;
        prev->next = NULL;
        return ret;
    }
};