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
    ListNode* reverseList(ListNode* head) {
        ListNode*  pre = NULL;
        ListNode* follow = NULL;
        while (head) {
            follow = head->next;
            head->next = pre;
            pre = head;
            head = follow;
        }
        return pre;
    }
};