// unique elements k must be returned

#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, k = 1;
        while(j<nums.size()){
            if (nums[i]==nums[j]){
                j++;
            }
            else {
                nums[i+1]=nums[j];
                i++;
                j++;
                k++;
            }
        }
        for(int a = 0; a < nums.size(); a++){
            cout << nums[a] << " ";
        }
        return k;
    }
};