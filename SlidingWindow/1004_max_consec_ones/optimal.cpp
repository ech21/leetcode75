class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0;
        int r = 0;
        int zeroCount = 0;
        int max_length = 0;
        while (r < nums.size()) {
            int current = 0;
            if (nums[r] == 0)
                zeroCount++;
            if (zeroCount > k) {
                //should be > k, not >= k. You're only moving the window when it's too big.
                if (nums[l] == 0)
                    zeroCount--;
                l++;
            }
            current = r - l + 1;
            
            //current should be done EVERY iteration, not just when k is maxed,
            //and remember that r > l, so r is on the right.
            max_length = max(max_length, current);
            r++;
        }
        return max_length;
    }
};


/*
Sliding window: Use two pointers. Keep track of amt of 0s in the window.
Check if r points to a 0, if so, increment. If this makes the count exceed k, 
move l right and check if we can decrement the count back to less than k.

Note that once the window is a certain length, the algorithm never shrinks the window size.
However, this is fine because we are checking the max length every iteration. We don't care about 
smaller valid windows, just the max.

Time complexity: O(n) where n is the length of nums.
Space complexity : O(1), since no space for output or extra space is used.

Another takeaway:
Get better at looking for bugs. The comments that are included in the code
are bugs that I found only by submitting to an AI.


*/