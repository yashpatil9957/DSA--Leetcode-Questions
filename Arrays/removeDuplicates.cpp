#include <bits/stdc++.h>
using namespace std;

//GIVEN ARRAY IS SORTED!!

int removeDuplicates(vector<int> &vec){
    int n = vec.size();
    int i = 0;
    //iteration
    for(int j=i+1; j<n; j++){
        if(vec[i] != vec[j]){
            i++;
            swap(vec[i], vec[j]);
        }
    }
    return i+1;
}

int main(){
    vector<int> arr1 = {1,1,2,2,2,3,3};
    vector<int> arr2 = {5,2,2,5,1,1,1};
    vector<int> arr3 = {1};
    cout<<removeDuplicates(arr1)<<endl;
    cout<<removeDuplicates(arr2)<<" Wrong!"<<endl;
    cout<<removeDuplicates(arr3)<<endl;
    return 0;
}