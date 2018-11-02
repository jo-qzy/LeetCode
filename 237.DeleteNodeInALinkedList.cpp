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
	void deleteNode(ListNode* node) {
		//思路就是把删除当前节点变成删除下一个节点
		ListNode* tmp = node->next;
		node->val = tmp->val;
		node->next = tmp->next;
		delete tmp;
	}
};