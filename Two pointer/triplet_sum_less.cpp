#include<iostream>
using namespace std;

// Given an integer array arr and an integer target, return the number of triplets chosen from the array that can make a sum less than target.

// main logic is that the since the array is sorted, the number between left and right pointers will also be less than the target, so we can add the number of triplets between left and right pointers to the answer and move the left pointer to right to find more triplets.

class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        int n = arr.size();
        int count=0;
        sort(arr.begin(),arr.end());
        for (int i = 0;i<n-2;i++){
            if (i>0&&arr[i]==arr[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            while (left < right){
                int add = arr[i]+arr[left]+arr[right];
                if (add<sum){
                    count+=right-left;
                    while(left<right && arr[left]==arr[left+1]){
                        left++;
                    }
                    while(left<right && arr[right]==arr[right-1]){
                        right--;
                    }
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return count ;
    }
};