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
			//如果没有节点或者只有一个节点，特殊处理
            return head;
        }
        ListNode * cur = head;
        ListNode * tmp = NULL;
        while (cur != NULL && cur->next != NULL)
        {
			//当当前节点的值和下一个节点的值相同，删除后一个节点
            if (cur->val == cur->next->val)
            {
                tmp = cur->next;
                cur->next = tmp->next;
                free(tmp);
            }
            else
            {
				//如果不相同就往后走一步
                cur = cur->next;
            }
        }
        return head;
    }
};