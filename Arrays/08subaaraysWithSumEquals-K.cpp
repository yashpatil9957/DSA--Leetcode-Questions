#include <bits/stdc++.h>
using namespace std;

//Brute approach - 3 nested loops
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        // Size of the array
        int n = arr.size();

        // Initialize count of subarrays
        int count = 0;

        // Traverse all possible start indices
        for (int i = 0; i < n; i++) {
            // Traverse all possible end indices from start
            for (int j = i; j < n; j++) {
                // Initialize sum for current subarray
                int sum = 0;

                // Calculate sum of subarray from i to j
                for (int m = i; m <= j; m++) {
                    sum += arr[m];
                }

                // If sum equals k, increment count
                if (sum == k) {
                    count++;
                }
            }
        }

        // Return total count of subarrays
        return count;
    }
};

//Better approach - 2 nested loops

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        // Size of the array
        int n = arr.size();

        // Initialize count of subarrays
        int count = 0;

        // Traverse all possible start indices
        for (int i = 0; i < n; i++) {
            // Initialize sum for current subarray
            int sum = 0;

            // Traverse all possible end indices from start
            for (int j = i; j < n; j++) {
                // Add current element to sum
                sum += arr[j];

                // If sum equals k, increment count
                if (sum == k) {
                    count++;
                }
            }
        }

        // Return total count of subarrays
        return count;
    }
};

//Optimal approach - prefix sum logic and hashmap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Size of the array
        int n = nums.size();

        // Map to store frequency of prefix sums
        unordered_map<int, int> mpp;

        // Initialize prefix sum and count of subarrays
        int currSum = 0;
        int result = 0;

        // Base case: prefix sum 0 has occurred once
        mpp[0] = 1;

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // Add current element to prefix sum
            currSum += nums[i];

            // Calculate the prefix sum that needs to be removed
            int remove = currSum - k;

            // If this prefix sum has been seen before,
            // add its count to the result
            if (mpp.find(remove) != mpp.end()) {
                result += mpp[remove];
            }

            // Update the frequency of the current prefix sum
            mpp[currSum]++;
        }

        // Return the total count of subarrays
        return result;
    }
};