#include<iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int>freq;
        // Take count of all characters in t
        for (int i = 0; i<= t.size(); i++){
            char c = t[i];
            freq[c]++;
        }
        int start = 0, low = 0, count =0, minLen = INT_MAX;
        for(int high =0;high <s.size();high++){
            // If the character is present in t, then decrement the count of that character in the map
            if(freq[s[high]]>0){
                count++;
            }
            freq[s[high]]--;
            while(count==t.size()){
                // check for minimum length
                if (high-low + 1<minLen){
                    minLen = high-low+1;
                    start = low;
                }
                // Increment the count of the character at low pointer in the map because we are going to move the low pointer ahead
                freq[s[low]]++;
                if(freq[s[low]]>0){
                    // If the character at low pointer is present in t, then decrement the count of that character in the map
                    count--;
                }
                low++;
            }
        }
        if(minLen==INT_MAX){
            return "";
        }
        else return s.substr(start,minLen);
    }
};