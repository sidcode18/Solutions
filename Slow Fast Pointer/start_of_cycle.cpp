#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *start = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast -> next-> next;
            if(slow==fast) break;
        }
        /*
        At this point, slow and fast have met somewhere inside the cycle.
        Let:
            L = distance from head to the beginning of the cycle
            X = distance from cycle beginning to the meeting point
            C = length of the cycle
        slow travels:
            L + X
        fast travels twice as far:
            2(L + X)
        Since fast has completed one or more extra loops around the cycle:
            2(L + X) = (L + X) + nC
        Therefore:
            L + X = nC
            L = nC - X
        This means:
            distance from head to cycle beginning = distance from meeting point to cycle beginning (moving around the cycle)
        Therefore, if we put one pointer at head and keep slow
        at the meeting point, then move both one step at a time,
        they will meet exactly at the beginning of the cycle.
        */
        if (fast==NULL || fast-> next == NULL) return NULL;
        while(start!=slow){
            slow = slow-> next;
            start = start->next;
        }
        return start;
    }
};