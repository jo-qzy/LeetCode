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

//解法3
class Solution3 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* fast = head;
		ListNode* slow = head;
		ListNode* new_head = head;
        int count = 0;
		//前两种方法更直观，这个方法是在前两种基础上优化了一下
		//虽然时间复杂度依旧为O(n)，但是相同情况下这种方法会少走k步
        if (head == NULL || k == 0)
        {
            return head;
        }
		while (k)
		{
            count++;
            if (k == 0 && fast->next == NULL)
            {
				//如果k为0说明已经找到那个需要翻转的链表的尾节点了
                break;
            }
            k--;//k的值减放此处是防止出现1,2然后旋转为2的情况出现
			//如果你不理解为什么放这里，将k--放在while便能知道
			fast = fast->next;
            if (fast == NULL)
			{
				k = k % count;
                if (k == 0)
                {
					//如果翻转长度为链表长度的倍数，相当于没翻转
                    return head;
                }
                fast = head;
			}
		}
		while (fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		new_head = slow->next;
		slow->next = NULL;
		fast->next = head;
		return new_head;
    }
};