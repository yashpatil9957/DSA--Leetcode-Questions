//Q. Reaarange the elements by signs

#include <bits/stdc++.h>
using namespace std;

//brute approach - using two arrays or stacks, one for storing positive elements other for storing negative elements.

//optimal approach - in one traversal
vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int posIdx = 0, negIdx = 1;

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[posIdx] = nums[i];
                posIdx += 2;
            }
            else {
                ans[negIdx] = nums[i];
                negIdx += 2;
            }
        }
        return ans;
    }