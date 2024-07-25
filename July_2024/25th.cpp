// 912. Sort an Array

// Without using any built-in sorting function

// All Sorting Algorithms
// 1. Bubble Sort
// 2. Selection Sort
// 3. Insertion Sort
// 4. Merge Sort
// 5. Quick Sort
// 6. Heap Sort
// 7. Counting Sort
// 8. Radix Sort

//  Quick Sort  - Complexity O(nlogn) - Average Case

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {

        // Quick Sort

        int n = nums.size();

        function<void(int, int)> quickSort = [&](int l, int r) {
            if (l >= r)
                return;

            int pivot = nums[(l + r) / 2];
            int i = l, j = r;

            while (i <= j)
            {
                while (nums[i] < pivot)
                    i++;
                while (nums[j] > pivot)
                    j--;

                if (i <= j)
                {
                    swap(nums[i], nums[j]);
                    i++;
                    j--;
                }
            }

            quickSort(l, j);
            quickSort(i, r);
        };


        quickSort(0, n - 1);

        return nums;

        
        
       
    }
};