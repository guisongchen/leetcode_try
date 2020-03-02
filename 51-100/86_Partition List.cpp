/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
// baisc idea, put small node in a new list, original list are all big ones, link two lists
// 1. create a new list, pick node whose value less than x linked at this new list
// 2. original list left nodes are all bigger than x now, link the head to the tail of new list

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};

// solution 2:
// relink nodes instead of create new list

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // basic idea:
        // if value less than x, hold steady, 
        // else check next until find node less than x
        // link that node between cur and original next
        
        // corner case
        if (!head)
            return head;
        
        // in case the first node is greater than x, use deamon node
        ListNode* deamon = new ListNode(0);
        deamon->next = head;
        
        ListNode* last = deamon;
        
        // big picture:
        //  last  cur    prev target   
        //   |    |       |   |
        //   1    4   3   5   2   2
        //      ^             |
        //      |_____________|
        //
        
        while (last->next) {
            ListNode* cur = last->next;
            
            // find next one which less than x
            ListNode* prev = last;  // prev node of target node
            while (cur && cur->val >= x) {
                prev = cur;
                cur = cur->next;
            }
            
            // if cur was moved
            // NOTE: cur may be null
            if (cur != last->next) {
                if (cur) {
                    prev->next = cur->next;
                    cur->next = last->next;
                    last->next = cur;
                } else {
                    break;
                }
            } else {
                last = cur;
            }
        }
        
        return deamon->next;
    }
};
