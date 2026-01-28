class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i ++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
        

    }
};

/*
The idea is that for every house, you have the option of skipping it or taking it. 
Taking it means you cannot take dp[i-1], and instead add it to dp[i-2]
Skipping it means you take dp[i-1]
You want the MAXIMUM of these two options.

dp[i] holds the highest total you can get from houses 0 thru i.

Time complexity: O(n) where n is the size of nums.
You iterate over the nums array once.
Space complexity: O(n) where n is the size of nums.
The dp vector has length n. 






*/