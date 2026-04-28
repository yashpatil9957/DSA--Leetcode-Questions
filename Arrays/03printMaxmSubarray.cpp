//Q. Return a subarray maximum subarray sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int curr = 0;

    for(int i=0; i<n; i++){
        curr += nums[i];
        maxSum = max(maxSum, curr);

        if(curr < 0) curr = 0;
    }
    return maxSum;
    }
};