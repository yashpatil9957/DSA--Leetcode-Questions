#include <bits/stdc++.h>
using namespace std;

//Kadane's pattern

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int power = 0;  //power is used therefore no element
        int nopower = arr[0];   //power is not used
        int ans = arr[0];

        for(int i=1; i<n; i++){
            int v1 = arr[i];
            int v2 = nopower + arr[i];
            int v3 = power + arr[i];
            int v4 = nopower;

            nopower = max(v1, v2);
            power = max(v3,v4);

            ans = max({ans, nopower, power});
        }
        return ans;
    }
};