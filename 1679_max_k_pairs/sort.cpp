#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        int count = 0;
        while(l < r){
            int sum = nums[l] + nums[r];
            if (sum == k){count++; l++; r--;}
            else if(sum < k){l++;}
            else{r--;}
        }
        return count;
    }
};

/*
Explanation: This algorithm uses a sorter to sort the numbers from lowest to highest.
Then, using two pointers, one at the start and one at the end, it checks the sum of the two numbers. 
If the sum is equal to k, we add one and move both pointers inward. If the sum is greater,
move the right pointer. If it's less, move the left pointer.
Stop when the pointers cross.

Time complexity: O(n log n) due to the sorting step. Pretty much all sorting algorithms are O(n log n). 
Note: the scanning IS O(n), but yes the sorting dominates.
Space complexity: O(1), no output or extra space used.



*/