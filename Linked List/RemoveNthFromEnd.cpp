#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

extern int listSize(ListNode* head);

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = listSize(head);
    int position = size - n + 1;
    if(position < 0) return nullptr;

    ListNode* last = nullptr, *curr = head;
    int i = 0;
    while(i != position - 1) {
        last = curr;
        curr = curr->next;
        i++;
    }

    if(last) {
        last->next = curr->next;
    }
    else {
        head = head->next;
    }
    curr->next = nullptr;
    return head;
}