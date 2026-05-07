/*  206.反转链表
    https://leetcode.cn/problems/reverse-linked-list/?envType=problem-list-v2&envId=2cktkvj
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reverse_head = NULL;
        while(head){
            ListNode *t = head -> next;
            head -> next= reverse_head;
            reverse_head = head;
            head = t;
        }
        return reverse_head;
    }
};