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
 ListNode* backup;
    bool isPalindrome(ListNode* head) {
        backup = head;
        return isPalindromeHelper(head);
    }

    bool isPalindromeHelper(ListNode* head) {
        if (NULL==head) return true;
        bool result = isPalindromeHelper(head->next) & (backup->val==head->val);
        backup = backup->next;
        return result;
    }
};