/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*****************

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* resListNode = new ListNode();
    ListNode* curListNode = resListNode;

    int rem = 0;

    while(l1 != nullptr || l2 != nullptr) {
        int val = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + rem;
        rem = val/10;

        ListNode* listNode = new ListNode(val%10);
        curListNode->next = listNode;

        curListNode = curListNode->next;

        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
    }

    if(rem != 0) {
        ListNode* listNode = new ListNode(rem);
        curListNode->next = listNode;
    }

    return resListNode->next;
}

int main() {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* resListNode = addTwoNumbers(l1, l2);

    while(resListNode != nullptr) {
        cout << (*resListNode).val << " ";
        resListNode = resListNode->next;
    }

    cout << endl;

    return 0;
}