#include <bits/stdc++.h>
using namespace std;

//Kadane's pattern

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxEnding = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++){
            int sumTill_i = maxEnding+nums[i];
            int sumAt_i = nums[i];

            maxEnding = max(sumTill_i, sumAt_i);
            ans = max(ans, maxEnding);
        }
        return ans;
    }
};