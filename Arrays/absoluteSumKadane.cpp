#include <bits/stdc++.h>
using namespace std;

//Kadane's pattern

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        //At 0th index 
        int maxEnding = nums[0];
        int minEnding = nums[0];

        int maxSum = maxEnding;
        int minSum = minEnding;

        for(int i=1; i<n; i++){
            int v1 = nums[i];
            int v2 = maxEnding + nums[i];
            int v3 = minEnding + nums[i];
            maxEnding = max(v1, v2);
            minEnding = min(v1, v3);
            maxSum = max(maxSum,maxEnding);
            minSum = min(minSum,minEnding);
        }
        return max(abs(maxSum), abs(minSum));
    }
};