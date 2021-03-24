/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

*****************

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode();
    ListNode* cur = res;

    while(true) {
        if(l1 == nullptr && l2 == nullptr) {
            break;
        } else {
            ListNode* l = nullptr;

            if(l1 != nullptr && l2 == nullptr) {
                l = l1;
                l1 = l1->next;
            } else if(l1 == nullptr && l2 != nullptr) {
                l = l2;
                l2 = l2->next;
            } else {
                if(l1->val < l2->val) {
                    l = l1;
                    l1 = l1->next;
                } else {
                    l = l2;
                    l2 = l2->next;
                }
            }

            cur->next = new ListNode(l->val);
            cur = cur->next;
        }
    }

    return res->next;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ListNode* l_1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l_2 = new ListNode(1, new ListNode(3, new ListNode(4)));

/*
    ListNode* l_1 = nullptr;
    ListNode* l_2 = nullptr;
*/
/*  
    ListNode* l_1 = nullptr;
    ListNode* l_2 = new ListNode(0);
*/
    ListNode* res = mergeTwoLists(l_1, l_2);

    while(res != nullptr) {
        cout << res->val << ' ';
        res = res->next;
    }
    cout << endl;

    return 0;
}