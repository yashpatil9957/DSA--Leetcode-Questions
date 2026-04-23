#include <bits/stdc++.h>
using namespace std;

//Q. Majority element (occurs more than n/2 times)

//1.Brute approach
int majorityElement(vector<int> &nums){
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(nums[i] == nums[j]){
                count++;
                if(count > n/2) return nums[i];
            }
        }
    }
    return -1;
}

//2.Better approach
int majorityElement(vector<int> &nums){
    int n = nums.size();
    unordered_map<int, int> mpp;

    for(int i=0; i<n; i++){
        mpp[nums[i]]++;
    }

    for(auto i=0; i<n; i++){
        if(mpp[nums[i]] > n/2) return nums[i];
    }

    return -1;
}

//3.Optimal approach
int majorityElement(vector<int> &nums){
    int n = nums.size();
    
    int n = nums.size();
    int cnt = 0;
    int element;

    for(int i=0; i<n; i++){
        if(cnt == 0){
            cnt = 1;
            element = nums[i];
        }
        else if(nums[i] == element) cnt++;
        else cnt--;
    }
    return element;
}