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
    bool hasCycle(ListNode *head) {
      if (!head) return false;
      ListNode * cur = head->next;
      ListNode * pre = head;
      while (cur) {
          if (cur==head) return true;
          pre = cur;
          cur = cur->next;
          pre -> next = head;
      }
      return false;  
    }
};