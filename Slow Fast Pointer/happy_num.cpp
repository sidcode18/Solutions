#include <iostream>
using namespace std;
class Solution {
public:
    int happy(int n){
            int rem , sum = 0;
            while(n!=0){
                rem = n%10;
                n = n/10;
                sum += rem*rem;
            }
            return sum ;
        }
    bool isHappy(int n) {
        int slow = n , fast = n;
        while(fast!=1){
            slow = happy(slow);
            fast = happy(happy(fast));
            // if slow and fast meet at a number other than 1, then it is not a happy number
            if(slow==fast && slow != 1){
                return false;
            }
        }
        return true;
    }
};