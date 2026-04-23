#include <bits/stdc++.h>
using namespace std;

//Q. Maximum subarray sum

//Brute appproach - selescting subarray and suming the element.
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = 0;

    for(int i=0; i<n; i++){
        int curr = 0;
        for(int j=i; j<n; j++){
            curr += nums[j];
            maxSum = max(maxSum, curr);
        }
    }
    return maxSum;

}

//Optimal approach -LADANE'S ALGORITHM
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