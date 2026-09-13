## Points to remember

- usually asked for sum of subarray, count, min, max of sub array no. of sub array with sum, or sum of left or right with a pivot or equillibrium
- for sub array with negative, where sum of i to j is equal to k or %k == 0, use hashmap
- shortest window with sum greater than k but with negative numbers, use Deque with prefix sum
- range sum with negative numbers as well, use merge sort on prefix sum array
- prefix sum = arr[i] + arr [i-1] + arr[i-2] ...
- prefix[i] = prefix[i-1] + arr[i-1]
- suffix[i] = suffix[i+1] + arr[i+1]
