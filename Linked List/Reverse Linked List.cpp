#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* newHead = nullptr;
    for(ListNode* curr = head; curr != nullptr;) {
        ListNode* node = curr;
        curr = curr->next;
        node->next = newHead;
        newHead = node;
    }
    return newHead;
}
