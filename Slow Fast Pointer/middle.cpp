#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast -> next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // slow covered half the distance fast covered, so once slow and fast are equal , slow wud reach half the dist -> middle
    }
};