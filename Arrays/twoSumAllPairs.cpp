#include<bits/stdc++.h>
using namespace std;
int twoSumAllPairs(vector<int> &nums, int target){
    int n = nums.size();
    if(n<2) return 0;
    int ans = 0;
    unordered_set<int> st;
    unordered_set<int> dup;

    for(int i=0; i<n; i++){
        int sum = target - nums[i];
        if(st.find(sum) != st.end() && dup.find(sum) == dup.end()){
            ans++;
            dup.insert(nums[i]);
            dup.insert(sum);
        }
        st.insert(nums[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 4, 2, 3, 5, 0};
    vector<int> nums2 = {1, 1, 2, 45, 46, 46};
    cout<<twoSumAllPairs(nums, 5)<<endl;
    cout<<twoSumAllPairs(nums2, 47)<<endl;
    return 0;
}