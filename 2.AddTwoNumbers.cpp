/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum = 0, carry = 0;
	struct ListNode* ret = NULL;
	struct ListNode* cur = NULL;
	struct ListNode* new_node = NULL;
	while ((l1 != NULL || l2 != NULL) || carry == 1)
	{
		sum = 0;
		if (l1 != NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		if (carry != 0)
		{
			sum += 1;
			carry = 0;
		}
		if (sum >= 10)
		{
			carry = 1;
		}
		new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
		new_node->val = sum % 10;
		new_node->next = NULL;
		if (ret == NULL)
		{
			ret = new_node;
			cur = new_node;
		}
		else
		{
			cur->next = new_node;
			cur = cur->next;
		}
	}
	return ret;
}