#include<bits/stdc++.h>
using namespace std;

//Optimal solution - sorting + 2-pointers
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int closest_sum = nums[0]+nums[1]+nums[2];

        for(int i=0; i<n-2; i++){
            //duplicate check
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];

                if(sum == target) return sum;
                else if(sum < target){
                    if(abs(target-sum) < abs(target-closest_sum)){
                        closest_sum = sum;
                    }
                    left++;
                }
                else{
                    if(abs(target-sum) < abs(target-closest_sum)){
                        closest_sum = sum;
                    }
                    right--;
                }
            }
        }
        return closest_sum;
    }
};