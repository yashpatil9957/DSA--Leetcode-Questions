#include <bits/stdc++.h>
using namespace std;

//Optimal approach - Sliding window
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0, res = 0;
        
        int low = 0, high = k-1;
        for(int i=low; i<=high; i++){
            sum += arr[i];
        }
        res = sum;
        
        while(high < n){
            low++;
            high++;
            if(high == n) break;
            sum += arr[high];
            sum -= arr[low-1];
            res = max(res, sum);
        }
        return res;
    }
};