#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

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
