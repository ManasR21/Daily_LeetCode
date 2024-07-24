Problem 2191: Sort the Jumbled Numbers
Medium

Description:

We are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

We are also given another integer array nums. Our task is to return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;  // To store mapped values and original indices

        // Process each number in the `nums` array
        for (int i = 0; i < nums.size(); ++i) {
            int mappedValue = 0;  // Initialize the mapped value
            int temp = nums[i];   // Copy the original number
            int place = 1;        // To keep track of place value (units, tens, hundreds, etc.)

            // Special case for zero
            if (temp == 0) {
                mappedValue = mapping[0];
            } else {
                // Map each digit of the number to its new value
                while (temp != 0) {
                    mappedValue = place * mapping[temp % 10] + mappedValue;
                    place *= 10;
                    temp /= 10;
                }
            }

            // Store the mapped value and original index
            storePairs.push_back({mappedValue, i});
        }

        // Sort based on the mapped values
        sort(storePairs.begin(), storePairs.end());

        // Reconstruct the sorted numbers from the original indices
        vector<int> answer;
        for (const auto& pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }

        return answer;
    }
};



Explanation:

Mapping Each Number:

For each number in nums, we convert it to its mapped value by iterating through its digits using the mapping array.
Special handling is done for 0 to directly use the mapped value.
Sorting:

We store each number’s mapped value and original index in storePairs.
We sort storePairs based on the mapped values to get the numbers in the correct order.
Extracting Sorted Numbers:

After sorting, we use the original indices to retrieve the numbers from nums in their new sorted order.
Edge Cases Considered:

Handling of zero as a special case.
Ensuring the sorting preserves the relative order for elements with the same mapped value.
