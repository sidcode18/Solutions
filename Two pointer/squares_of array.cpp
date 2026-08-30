#include <iostream>
using namespace std;
class Solution {
public:

// Two pointer solution below -> O(n) time complexity and O(n) space complexity

    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0, j = n - 1;
        for (int k = n - 1; k >= 0; k--) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans[k] = nums[i] * nums[i];
                i++;
            } else {
                ans[k] = nums[j] * nums[j];
                j--;
            }
        }
        return ans;
    }
};

// Merge sort solution below -> O(n) time complexity and O(n) space complexity

//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> a, b;
//         for (int i = 0; i < n; i++) {
//             int x = nums[i] * nums[i];
//             if (nums[i] >= 0)
//                 a.push_back(x);
//             else
//                 b.push_back(x);
//         }
//         reverse(b.begin(), b.end());
//         vector<int> ans;
//         int i = 0, j = 0;
//         while (i < a.size() && j < b.size()) {
//             if (a[i] < b[j]) {
//                 ans.push_back(a[i]);
//                 i++;
//             } else {
//                 ans.push_back(b[j]);
//                 j++;
//             }
//         }
//         while (i < a.size()) {
//             ans.push_back(a[i]);
//             i++;
//         }
//         while (j < b.size()) {
//             ans.push_back(b[j]);
//             j++;
//         }
//         return ans;
//     }
// };