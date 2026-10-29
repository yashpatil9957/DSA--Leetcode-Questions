#include<bits/stdc++.h>
using namespace std;

//Optimal approach - Variable sliding window
class Solution {
public:
    int maxi(vector<int>vec){
        int ans = INT_MIN;
        for(auto i: vec){
            ans=max(ans, i);
        }
        return ans;
    }

    int characterReplacement(string s, int k) {
        vector<int>freq(26, 0);
        int n=s.length();

        int low =0, high=0;
        int res = INT_MIN;

        for(high=0; high<n; high++){
            freq[s[high]-'A']++;

            int len=high-low+1;
            int maxFreq=maxi(freq);
            int diff=len-maxFreq;

            while(diff > k){
                freq[s[low]-'A']--;
                low++;

                len=high-low+1;
                maxFreq=maxi(freq);
                diff=len-maxFreq;
            }
            // len=high-low+1;
            res=max(res, len);
        }
        return res;   
    }
};