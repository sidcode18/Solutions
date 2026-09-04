#include <iostream>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0, low = 0;
        // Initialize the sum of the first k elements of the array. This is done to set up the initial window for the sliding window technique.
        for (int i = 0 ; i < k ; i++){
            sum = sum + arr[i];
        }
        int ans = sum;
        //The high pointer moves forward from target size to include new elements in the window, while the low pointer moves forward to exclude elements from the window, maintaining the size of the window at k.
        for(int high = k; high < n; high ++){
            // The sum is updated by adding the new element at the high pointer and subtracting the element at the low pointer.
            sum -= arr[low];
            ans = max(ans,sum);
            low++;
        }
        return ans;
    }
};