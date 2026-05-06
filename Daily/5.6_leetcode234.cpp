/*  234.回文链表
    https://leetcode.cn/problems/palindrome-linked-list/description/?envType=problem-list-v2&envId=2cktkvj
*/

#include <iostream>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast;
        ListNode *slow;
        fast = head;
        slow = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode *reverse_head = NULL;
        while(slow){
            ListNode *t = slow -> next;
            slow -> next = reverse_head;
            reverse_head = slow;
            slow = t;
        }

        while(reverse_head){
            if(reverse_head -> val == head -> val){
                reverse_head = reverse_head -> next;
                head = head -> next;
            }else{
                return false;
            }
        }
        return true;
    }
};