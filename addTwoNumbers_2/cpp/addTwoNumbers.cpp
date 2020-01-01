/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//从头遍历l1和l2 并增加一个进位的变量
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = NULL, *prev = NULL;
    int carry = 0;
    while (l1 || l2) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int value = v1 + v2 + carry;
        ListNode *node = new ListNode(value % 10);
        carry = value / 10;
        if (!head) head = node;
        if (prev)
            prev->next = node;
        prev = node;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    if (carry) {
        ListNode *node = new ListNode(carry);
        prev->next = node;
    }

    return head;
}



