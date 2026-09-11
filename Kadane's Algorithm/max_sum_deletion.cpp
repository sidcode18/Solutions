#include<iostream>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& arr) {

        // noDelete -> maximum sum ending at the current position without deleting anything
        // oneDelete -> maximum sum ending at the current position with exactly one deletion

        int noDelete = arr[0];
        int oneDelete = 0;
        int ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            // If we delete arr[i], the previous noDelete sum is used.
            // Otherwise, continue the previous oneDelete subarray.
            oneDelete = max(noDelete, oneDelete + arr[i]);
            // Normal Kadane's algorithm:
            // either start a new subarray at arr[i],
            // or extend the previous subarray.
            noDelete = max(arr[i], noDelete + arr[i]);
            ans = max(ans, max(noDelete, oneDelete));
        }
        return ans;
    }
};