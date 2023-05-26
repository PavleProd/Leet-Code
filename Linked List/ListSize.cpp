#include "ListNode.h"

int listSize(ListNode* head) {
    int size = 0;
    while(head != nullptr) {
        head = head->next;
        size++;
    }

    return size;
}