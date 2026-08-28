#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0 ; // vector indexing starts from 0 
        int j = numbers.size() - 1 ;
        while (i<j){
            if (numbers[i]+numbers[j] == target){
                return {i+1,j+1} ; // return in vector but asked for start index 1 so increment
            }
            else if (numbers[i]+numbers[j] > target){
                j--;
            }
            else {
                i++;
            }
        }
        return {};
    }
};