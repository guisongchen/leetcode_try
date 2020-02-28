/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* cur = head;
        int cnt = 0;
        while (cur) {
            cur = cur->next;
            cnt++;
        }
        
        ListNode* last;
        //ListNode* next;
        
        // corner case, if n == cnt, last is null
        if (n == 1) {
            
            // if last exist
            if (cnt >= 2) {
                last = head;
                for (int i = 1; i <= cnt-n-1; i++)
                    last = last->next;
            } else { // if cnt = n = 1
                return nullptr;
            }
            
            last->next = nullptr;
            
        } else if (n == cnt) {// corner case, if n == cnt && n > 1, last is null
            head = head->next;
        } else { // remove target neither begin or end, last and next exist, cnt >= 3
            last = head;
            for (int i = 1; i <= cnt-n-1; i++)
                last = last->next;
            cur = last->next; // remove target
            //next = cur->next;
            last->next = cur->next;
        }
        return head;
    }
};
