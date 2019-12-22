/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // define return value, and create a pointer link to it
        
        // the start node, we use it as return, and should not change after create 
        // NOTE: init as null
        ListNode* res = NULL;
        
        // since start node untouchble, we use pointer to handle traverse
        // why pointer to pointer? 
        // return value is a node of list, we need to travese list,
        // so use a pointer to pointer
        // at the beginning, rp is point to res
        ListNode** rp = &res;
        
        // three steps to handle this
        // step 1: get value from list
        // --> get one digit a time, then move the next pointer
        // step 2: sum and store carry
        // --> carry should add on next value
        // step 3: save sum num and carry in result
        // --> if the last carry exist, need a new node
        
        int carry = 0;
        int n1 = 0, n2 = 0, sum = 0;
        while (l1 || l2) {
            // step 1: get value
            n1 = getDigitAndMoveNext(l1);
            n2 = getDigitAndMoveNext(l2);
            
            // step 2: sum and store carry
            // NOTE: set carry zero and use it at the beginning
            sum = n1 + n2 + carry;
            carry = sum/10;
            
            // step 3: save result
            ListNode* node = new ListNode(sum%10);
            *rp = node;
            
            // pointer move to next
            rp = &(node->next);
        }
        
        // corner case:
        // handle the last carry, if exist create a new node
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            *rp = node;
        }
        
        return res;
        
    }
private:
    // use reference to travese list
    int getDigitAndMoveNext(ListNode* &ln) {
        // this must set zero here, if one list null, should return 0
        // this may happened if one list is shorter than the other one
        int x = 0;
        
        // null juadge
        if (ln) {
            x = ln->val;
            ln = ln->next;
        }
        return x;
    }
};
