#include <bits/stdc++.h>
using namespace std;

class Solution{
    //brute - traverse the string elements/characters one by from end and simultaneously keep adding them in stack. Once traversed fully, take out characters added in stack building the string => reversed string
    //TC->O(2n), SC->O(n)
    bool pallindromeString(string s){
        int n = s.length();
        stack<char>st;
        for(int i=0; i<n; i++){
            st.push(s[i]);
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        if(ans == s) return true;
        else false;
    }

    //optimal - using two pointers, one pointing to starting index while other to the end. At each iteration will check character at starting and ending pointer.If same then pallindrome else not.
    bool pallindromeString(string s){
        int n = s.length();
        int i=0, j=n-1;

        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

};