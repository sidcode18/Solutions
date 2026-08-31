#include<iostream>
using namespace std;

/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/

// So this can be converted to nums[j]+nums[k] = -nums[i] and then we can use two pointer approach to find the pairs of nums[j] and nums[k] such that their sum is equal to -nums[i].

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>a; // vector to store the vector of triplets
        sort(nums.begin(),nums.end());
        for (int i = 0;i<n-2;i++){ // cuz atleast 3 elements are needed to form a triplet, so we can stop at n-2
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1; // left pointer starts from the next element of i otherwise same as i 
            int right = n-1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0){
                    a.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left]==nums[left+1]){
                        left++; // if next element is same as current element then we can skip it to avoid duplicates
                    }
                    while(left < right && nums[right]==nums[right-1]){
                        right--; // simlarly if next element from right is same as current element then we can skip it to avoid duplicates
                    }
                    left++; // run the loop for next set of elements
                    right--;
                }
                else if (sum<0){
                    left++; // if sum is less than 0 then we need to increase the sum so we move the left pointer to right
                }
                else{
                    right--;
                } 
            }
        }
        return a;
    }
};