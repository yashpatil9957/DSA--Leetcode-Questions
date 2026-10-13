#include<bits/stdc++.h>
using namespace std;

//Optimal solution - sorting and 2-pointers 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){
            //important check
            if(i>0 && nums[i] == nums[i-1]) continue;
            int x = -nums[i];
            //Run two sum for each nums[i];
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[left] + nums[right];

                if(sum == x){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    //check for duplicates
                    while(left<n && nums[left] == nums[left-1]){
                        left++;
                    }
                    while(right>=0 && nums[right] == nums[right+1]){
                        right--;
                    }
                }
                else if(sum < x){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return ans;
    }
};