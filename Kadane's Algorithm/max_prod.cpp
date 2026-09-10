#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // product of neg and neg is positive, this is where the usual template for sum or diff fails, we need to keep track of the min product as well, because if we have a negative number and we multiply it with the min product, we can get a max product.
        int n = nums.size(), a, b, c;
        int ans = nums[0], minend = nums[0], maxend = nums[0];
        for (int i = 1; i < n; i++){
            a = nums[i];
            // maxend and minend are the max and min product we can get till the previous index, we multiply them with the current element to get the max and min product we can get till the current index.
            b = minend * nums[i]; // to handle neative number being left out while multipying
            c = maxend * nums[i];
            // we take the max of the three values to get the max product we can get till the current index, and we take the min of the three values to get the min product we can get till the current index.
            maxend = max(a,max(b,c));
            minend = min(a,min(b,c));
            // we take the max of the max product we can get till the current index and the max product we have found so far to get the max product we can get till the current index.
            ans = max(ans,max(maxend,minend));
        }
        return ans;
    }
};