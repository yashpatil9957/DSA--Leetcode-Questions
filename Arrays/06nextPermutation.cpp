//Q. Find next permutation = lexicographically next for given permutation

#include <bits/stdc++.h>
using namespace std;

//brute approach - generate all the permutations and find its next one

//optimal approach
void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPt = -1;   //breaking point

        // finding 1st smaller ele than its next one from the end
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                breakPt = i;
                break;
            }
        }
        
        //if no breaking pt then it is last permutation -> reverse nums
        if(breakPt == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //finding first greater ele than breaking pt element
        for(int i=n-1; i>breakPt; i--){
            if(nums[i] > nums[breakPt]){
                swap(nums[i], nums[breakPt]);
                break;
            }
        }
        //reverse from breaking pt next till end
        reverse(nums.begin()+breakPt+1, nums.end());
    }