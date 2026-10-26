#include<bits/stdc++.h>
using namespace std;

//Optimal approach - Variable sliding window
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.length();
        int res = -1;
        int low =0, high =0;
        unordered_map<char, int>freq;
        //sliding window - variable size
        for(int high=0; high<n; high++){
            freq[s[high]]++;
            
            while(freq.size() > k){
                freq[s[low]]--;
                if(freq[s[low]] == 0) freq.erase(s[low]);
                low++;
            }
            if(freq.size() == k){
                int len = high-low+1;
                res = max(len, res);
            }
        }
        return res;
    }
};