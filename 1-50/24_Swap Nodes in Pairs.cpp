/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// solution 1:

// keypoints:
// 1. use deamon node to return swaped list
// 2. deamon node act as prev node, notice prev node has no change during swap
// 3. handling swap problem, we usually hanlde from next to cur(end to start)
// 4. careful about corner cases

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        // use deamon node to return head of swaped list
        
        // corner case
        if (!head)
            return head;
        
        //  prev     cur      next
        //   |        |         |               
        // deamon -- head -- head->next -- head->next->next 
        //
        //  prev     next      cur
        //   |        |         |               
        // deamon -- head -- head->next -- head->next->next 
        ListNode* deamon = new ListNode(0);
        deamon->next = head;
        ListNode* prev = deamon;
        ListNode* cur = head;
        
        while (cur && cur->next) {
            
            // swap pair cur and next
            ListNode* next = cur->next;
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            
            // update prev, cur
            prev = cur;
            cur = cur->next;
        }
        
        return deamon->next;
        
    }
};


// solution 2:

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // null case
        if (!head || !head->next)
            return head;
        
        // recursive method is from end to begin
        // let's consider from begin to end
        
        // use guarder to keep the head node of swaped list
        ListNode* guarder = head->next;
        
        // before  swap:  guarder  head   next  next->next        next->next->next
        // after 1 swap:  guarder  next   head  next->next        next->next->next
        // after 2 swap:  guarder  next   head  next->next->next  next->next
        //                                  |       |
        //                                  |_______| <-- DO NOT FORGET
        //
        // stop condition: head or head->next is null

        ListNode* last = guarder;
        ListNode* next;
        
        // head->next NOT always exist
        // DO NOT use which(head && next)
        while (head && head->next) {
            // swap
            // handle head->next before next change
            next = head->next;
            head->next = next->next;
            next->next = head;
            last->next = next;
            
            // update last pointer and next pointer
            last = head;
            head = head->next;
        }
        
        return guarder;
    }
};
