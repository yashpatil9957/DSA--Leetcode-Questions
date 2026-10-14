#include <bits/stdc++.h>
using namespace std;

//Optimal solution- sorting and 2-pointers
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<2) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        int left=0, right=n-1;
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum < target){
                ans = ans+(right-left);
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};