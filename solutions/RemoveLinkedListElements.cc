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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val==val) head = head->next;
        if (!head) return head;
        ListNode * cur = head;
        ListNode * pre = head;
        while (cur) {
            if (cur->val==val) {
                pre->next = cur->next;
                cur = cur->next;
            } 
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};