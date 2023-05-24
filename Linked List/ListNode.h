#ifndef LEET_CODE_LISTNODE_H
#define LEET_CODE_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
ListNode* head = new ListNode(1);
    ListNode* last = head;
    for(int i = 2; i <= 5; i++) {
        ListNode* node = new ListNode(i);
        last->next = node;
        last = node;
    }

    for(ListNode* curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->val << " ";
    }
    cout << "\n";

    head = reverseList(nullptr);

    for(ListNode* curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->val << " ";
    }
*/

#endif //LEET_CODE_LISTNODE_H
