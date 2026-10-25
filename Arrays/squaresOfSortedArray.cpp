#include <bits/stdc++.h>
using namespace std;
vector<int> sqOfSortedArray(vector<int>&arr){
    int n = arr.size();
    vector<int> ans;

    int flag = -1;
    for(int i=0; i<n; i++){
        if(arr[i]<0) flag = i;
    }
    reverse(arr.begin(), arr.begin()+flag+1);
    //square till flag
    for(int j=0; j<n; j++){
        arr[j]= arr[j]*arr[j];
    }
    int i=0, j=flag+1;
    while(i<flag+1 && j<n){
        if(arr[i]<arr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(arr[j]);
            j++;
        }
    }
    if(i>flag){
        while(j<n){
            ans.push_back(arr[j]);
            j++;
        }
    }
    if(j>n){
        while(i<flag+1){
            ans.push_back(arr[i]);
            i++;
        }
    }
    return ans;
}

int main(){
    vector<int>nums = {-4, -1, 0, 3, 10};
    vector<int>soln = sqOfSortedArray(nums);
    for(int i=0; i<soln.size(); i++){
        cout<<soln[i]<<' ';
    }
    cout<<endl;
    return 0;
}