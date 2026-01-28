class Solution {
public:
    int tribonacci(int n) {
        std::unordered_map<int, int> memo;
        return helper(n, memo);
    }
    
private:
    int helper(int n, std::unordered_map<int, int>& memo) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        int result;
        if (n == 0) {
            result = 0;
        } else if (n == 1 || n == 2) {
            result = 1;
        } else {
            result = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3, memo);
        }
        
        memo[n] = result;
        return result;
    }
};

/*
Basics of dynamic programming: Keep a memory of the state, so that things do not need to be recomputed. 
In this case, it's memo.


Here is the iterative form of it (faster)

*/
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }
        
        std::vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        
        return dp[n];
    }
};