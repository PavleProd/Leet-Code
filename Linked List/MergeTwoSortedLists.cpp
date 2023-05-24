#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* curr1 = list1, *curr2 = list2;
    ListNode* head = nullptr, *last = nullptr;
    while(curr1 || curr2) {
        if(curr1 && curr2) {
            if(curr1->val < curr2->val) {
                if(!head) {
                    head = curr1;
                }
                else {
                    last->next = curr1;
                }
                last = curr1;
                curr1 = curr1->next;
            }
            else {
                if(!head) {
                    head = curr2;
                }
                else {
                    last->next = curr2;
                }
                last = curr2;
                curr2 = curr2->next;
            }
        }
        else if(curr1) {
            if(!head) {
                head = curr1;
            }
            else {
                last->next = curr1;
            }
            last = curr1;
            curr1 = curr1->next;
        }
        else {
            if(!head) {
                head = curr2;
            }
            else {
                last->next = curr2;
            }
            last = curr2;
            curr2 = curr2->next;
        }
    }
    return head;
}
