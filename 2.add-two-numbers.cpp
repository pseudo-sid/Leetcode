/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dum = new ListNode();
        ListNode* head = dum;
        int carry = 0;
        while(l1 != nullptr or l2 != nullptr){
            int x = l1 != nullptr? l1->val : 0;
            int y = l2 != nullptr? l2->val : 0;
            int s = x + y + carry;
            carry = s/10;
            head->next = new ListNode(s % 10);
            head = head->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if(carry)
            head->next = new ListNode(carry);
        return dum->next;
    }
};
// @lc code=end

