//Q. Buy and sell stock problem

#include <bits/stdc++.h>
using namespace std;

//Brute solution-
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                maxProfit = max(maxProfit, prices[j]-prices[i]);
            }          
        }
        return maxProfit;
    }
};

//Optimal solution-
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minBuy = INT_MAX;   // track minimum buy till that day

        for(int i=0; i<n; i++){
            minBuy = min(minBuy, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minBuy);
        }
        return maxProfit;
    }
};