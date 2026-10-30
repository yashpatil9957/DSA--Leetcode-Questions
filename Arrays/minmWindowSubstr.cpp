#include<bits/stdc++.h>
using namespace std;

//Optimal approach - Variable sliding window
class Solution {
public:
    bool valid(vector<int> &have, vector<int> &needed){
        for(int i=0; i<256; i++){
            if(have[i] < needed[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";

        int res=INT_MAX;
        int low=0, high=0;
        int start = 0;  //to store possible starting of the substring

        vector<int> have(256,0);
        vector<int> needed(256,0);
        for(int i=0; i<t.size(); i++){
            needed[t[i]]++;
        }

        for(high=0; high<s.size(); high++){
            have[s[high]]++;

            while(valid(have, needed)){
                int len = high-low+1;
                if(len < res){
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(res == INT_MAX) return "";
        return s.substr(start, res);
    }
};