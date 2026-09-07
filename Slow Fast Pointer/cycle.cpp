#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    // Constructor
    ListNode(int x) : val(x), next(NULL) {}
    // val(x), next(NULL) -> member initializer list
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // head points to the first node of the linked list
        // slow moves one node at a time
        ListNode *slow = head;
        // fast also starts at the first node
        // fast moves two nodes at a time
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            // Move slow by 1 node
            slow = slow->next;
            // Move fast by 2 nodes
            fast = fast->next->next;
            // If they point to the same node, a cycle exists
            if (fast == slow) {
                return true;
            }
        }
        // fast reached NULL → no cycle
        return false;
    }
};