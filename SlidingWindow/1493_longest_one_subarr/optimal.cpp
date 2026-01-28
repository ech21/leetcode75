class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, best = 0;
        int zeroCount = 0; 
        while(r < nums.size()){
            if(nums[r] == 0) zeroCount ++;
            if(zeroCount > 1){
                if(nums[l] == 0) zeroCount--;
                l++;
            }
            int current = r - l;
            //the element is getting deleted, not replaced.
            best = max(current, best);
            r++;
        }
        return best;
    }
};

/*
This code is nearly identical to the code for 1004, except
that k is always 1. The only other difference is that when calculating
the length of the current window, it's r -l instead of r - l + 1,
because we are deleting the one element that's 0, not replacing it.

Time complexity: O(n) where n is the length of nums.
Space complexity : O(1), since no space for output or extra space is used.

*/