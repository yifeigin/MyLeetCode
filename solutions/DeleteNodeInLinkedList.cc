//Yifei Wang
// LeetCode Question 237

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// All following solutions have the same running time

 // First Solution:
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * cur = node;
        ListNode * pre = node;
        while(cur->next) {
            cur->val = cur->next->val;
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
     }
};

// Second (improved):
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        
     }
};

// Last:
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node->next) {
            node = NULL;
        }
        else {
            node->val = node->next->val;
            node->next = node->next->next;
        }
     }
};
