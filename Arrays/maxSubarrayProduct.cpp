#include <bits/stdc++.h>
using namespace std;

//Kadane's pattern

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); i++){
            int pdtAt_i = nums[i];
            int maxPdtTill_i = maxEnding*nums[i];
            int minPdtTill_i = minEnding*nums[i];

            maxEnding = max(pdtAt_i, max(maxPdtTill_i, minPdtTill_i));
            minEnding = min(pdtAt_i, min(maxPdtTill_i, minPdtTill_i));

            ans = max(ans, max(maxEnding, minEnding));
        }
        return ans;
    }
};