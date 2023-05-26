#include <bits/stdc++.h>
#include "ListNode.h"

extern ListNode* reverseList(ListNode* head);
extern int listSize(ListNode* head);


// Ideja: invertujemo desnu polovinu liste i  onda naizmenicno uvezujemo originalnu listu sa invertovanom
void reorderList(ListNode* head) {
    int lstSize = listSize(head);
    int rightHalf = lstSize / 2 + (lstSize&1);
    if(rightHalf == 0) return;

    ListNode* rightCurr = head;
    ListNode* last = nullptr;
    int i = 0;
    while(i != rightHalf) {
        i++;
        last = rightCurr;
        rightCurr = rightCurr->next;
    }

    last->next = nullptr;

    rightCurr = reverseList(rightCurr);
    ListNode* leftCurr = head;
    while(rightCurr) { // desna strana ce garantovano biti <= zbog deljenja celebrojno sa 2
        ListNode* l = leftCurr;
        leftCurr = leftCurr->next;
        ListNode* r = rightCurr;
        rightCurr = rightCurr->next;
        l->next = r;
        r->next = leftCurr;
    }
}