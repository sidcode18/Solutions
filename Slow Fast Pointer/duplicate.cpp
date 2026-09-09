#include<iostream>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true){
            // find the meeting point inside the cycle
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow==fast){
                break;
            }
        }
        slow = 0;
        // find the entrance to the cycle
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
            }
        return slow;
    }
};