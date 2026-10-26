#include<bits/stdc++.h>
using namespace std;

//Optimal approach - Variable sliding window
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int res = -1;
        unordered_map<int, int>basket;
        int low=0, high=0;

        for(int high=0; high<n; high++){
            basket[fruits[high]]++;

            while(basket.size()>2){
                basket[fruits[low]]--;
                if(basket[fruits[low]] == 0) basket.erase(fruits[low]);
                low++;
            }
            //atleast 2 is covered no need of if condition!
            int len = high-low+1;
            res = max(res, len);
        }
        return res;
    }
};