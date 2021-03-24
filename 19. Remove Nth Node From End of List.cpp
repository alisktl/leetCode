/*
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

*****************

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* head_2 = head;

    vector<ListNode*> nodes;

    while(head_2 != nullptr) {
        nodes.push_back(head_2);
        head_2 = head_2->next;
    }

    ListNode* node_to_remove = nodes[nodes.size()-1-(n-1)];
    ListNode* next_node = nullptr;
    ListNode* prev_node = nullptr;

    if(n != 1) {
        next_node = nodes[nodes.size()-1-(n-2)];
    }
    if(nodes.size()-1-(n-1) != 0) {
        prev_node = nodes[nodes.size()-1-(n)];
    }

    if(prev_node != nullptr && next_node != nullptr) prev_node->next = next_node;
    else if(prev_node == nullptr && next_node != nullptr) head = next_node;
    else if(prev_node != nullptr && next_node == nullptr) prev_node->next = nullptr;
    else if(prev_node == nullptr && next_node == nullptr) head = nullptr;

    return head;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ListNode l = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* res = removeNthFromEnd(&l, 2);
/*
    ListNode l = ListNode(1);
    ListNode* res = removeNthFromEnd(&l, 1);
*/
/*
    ListNode l = ListNode(1, new ListNode(2));
    ListNode* res = removeNthFromEnd(&l, 1);
*/
    while(res != nullptr) {
        cout << res->val << ' ';
        res = res->next;
    }

    cout << endl;
}