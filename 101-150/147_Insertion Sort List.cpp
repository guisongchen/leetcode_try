/*

Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;
        
        // since list can go back to begin, thing is tricky here
        // we create a new list using deamon, add one node each time and sort it
        // keypoints:
        // 1. separator node from old list
        // 2. compare separated note with nodes in new list, put in right place
        
        ListNode* deamon = new ListNode(0);
        deamon->next = head; // init new list the same head of old one 

        // seperator head node away from old list
        // we set current added node, reset next point to null
        // by doing this we can compare cur added node and nodes added before
        // otherwise we will make old list and new list intersected, which is tragedy
        // since head is the first and only node in new list, set head->next null
        ListNode* cur = head->next;
        head->next = nullptr;
        
        // compare separator node with nodes in new list
        // prev->next is the head of new list
        while (cur) {
            
            ListNode* prevOfNewList = nullptr;
            ListNode* curOfNewList = deamon->next;
            while (curOfNewList && curOfNewList->val <= cur->val) {
                prevOfNewList = curOfNewList;
                curOfNewList = curOfNewList->next;
            }
            
            // cur should be put ahead of curOfNewList
            
            // keep next pointer before change to update cur
            ListNode* next = cur->next;
            
            // new: deamon --> deamon->next --> ...--> prevOfNewList --> curOfNewList -->..
            //                                                       |     |
            // old:                                                  --cur--- cur->next --
            
            // curOfNewList maybe null or less than cur
            // if null, we add cur to the end of new list
            // if not, means cur is between prevNew and curNew
            cur->next = curOfNewList;
            
            if (prevOfNewList)
                prevOfNewList->next = cur;
            else // if prevOfNewList is null, means cur is small than cur head, update head
                deamon->next = cur;
 
            cur = next; // update cur pointer of old list
        }
        
        return deamon->next;
        
    }
};
