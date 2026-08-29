## Points to remember
- Usually array or linkedlist is used to solve
- If it's sorted array or sort ourselves / asked to rearrange, merge or remove duplicates, this pattern can be used
- Detect cycle in linkedlist
- To find pair of or triplets or quadruplets
- If asked to return the pair of numbers itself then two pointer can be used unlike if index is asked then sorting cannot be done as the value in an index changes with sorting(unless it is sorted beforehand)
- Hashmap can traverse in order of n[O(n)] but also uses up O(n) space as well to store the value in each index
- Used when space cannot be compromised.
- Sorting is done so that when i is first element and j is last element, let's say arr[i]+arr[j] is greater than target, there is no sense in incrementing i because right of i is only number greater than i in sorted array which means the next sum will also be greater than target, so j will be decremented to achieve the target and vice versa for sum less than target
- The code must run only while i > j because if i is equal or greater that means it crossed each other where all possibilities have been checked but target hasn't been found yet

