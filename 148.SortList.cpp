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
    ListNode* sortList(ListNode* head) {
        quickSort(head, NULL);
        return head;
    }
private:
	//快速排序思想
    void quickSort(ListNode* head, ListNode* end)
    {
        if (head == end)
        {
            return;
        }
        ListNode* div = partSort(head, end);//划分区间
        if (head != div && head->next != div)
        {
			//如果左边的数大于等于两个，继续排
            quickSort(head, div);
        }
        if (div->next != end && div->next->next != end)
        {
			//如果右边的数大于等于两个，继续排
            quickSort(div->next, end);
        }
    }
    
    ListNode* partSort(ListNode* head, ListNode* end)
    {
		//把最左边的节点的值作为key
		//这里移数据采用快慢指针法，其他的快排方法如挖坑和左右指针不适合链表
        int key = head->val;
        int tmp = 0;
        ListNode* slow = head;
        ListNode* fast = slow->next;
        ListNode* prev = head;//prev指的是slow的前一个节点
        while (fast != end)
        {
			//当快指针的值小于key时，慢指针走一步
            if (fast->val <= key)
            {
                prev = slow;
                slow = slow->next;
				//慢指针走动后如果和快指针不重合，就交换两数
                if (slow != fast)
                {
                    tmp = slow->val;
                    slow->val = fast->val;
                    fast->val = tmp;
                }
            }
            fast = fast->next;
        }
		//走完之后有三种情况：
		//情况1：
		//所有的值都比key小，这个时候要交换第一个数和最后一个数
		//slow刚好指向最后一个数
        if (fast == end)
        {
            prev = slow;
        }
		//情况2:
		//所有的值都比key大，那么也就不需要交换
		//但是由于prev一开始就指向head，所以交换不交换不影响
		//情况3：
		//一般情况，slow指向的数是比key大的数，所以要把slow前面的数(prev)和head交换
        tmp = prev->val;
        prev->val = head->val;
        head->val = tmp;
        return prev;
    }
};