#include <bits/stdc++.h>
using namespace std;

//Kadane's pattern

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        //i=0 iteration
        int totalSum = nums[0];

        int maxEnding = nums[0];
        int maxSum = nums[0];

        int minEnding = nums[0];
        int minSum = nums[0];

        for(int i=1; i<n; i++){
            totalSum+=nums[i];

            maxEnding = max(nums[i], maxEnding+nums[i]);
            maxSum = max(maxSum, maxEnding);

            minEnding = min(nums[i], minEnding+nums[i]);
            minSum = min(minSum, minEnding);
        }
        //if all elements in array are negative
        if(maxSum < 0) return maxSum;   
        return max(maxSum, totalSum-minSum);

    }
};