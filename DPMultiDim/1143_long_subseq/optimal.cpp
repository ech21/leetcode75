
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = (int)text1.size();
        int n = (int)text2.size();

        // Always make dp the shorter dimension to use O(min(m,n)) space
        if (n > m) {
            swap(text1, text2);
            swap(m, n);
        }

        vector<int> dp(
            n + 1,
            0); // dp[j] = LCS of text1[0..i-1] and text2[0..j-1] for current i

        for (int i = 1; i <= m; i++) {
            int prevDiag = 0; // this will represent dp[i-1][j-1]
            for (int j = 1; j <= n; j++) {
                int savedUp = dp[j]; // dp[i-1][j] before we overwrite dp[j]

                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prevDiag + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]); // max(up, left)
                }

                prevDiag = savedUp; // move diagonal forward for next j
            }
        }

        return dp[n];
    }
};
/*
This is a multidimensional DP problem. 
Say that i is the number of letters currently in the sub string (so max i is text1.length()). 
Say that j is the same thing for text2. 
This means the best solution for a substring length i and a substring length j is the maximum
between a subtring length i-1 and substring length j, and a substring length i and substring length j -1. 
The intuition behind this is that if the current letters that we're looking at aren't the same, then one of them
will eventually be skipped over when creating the longest common subsequence.
If the current letters ARE the same, then we add one to the best solution between a substring length i-1 and j-1. 
This makes sense, as that if both are the same letter, there's no need to look at it again, it will be in the subsequence.

The solution ABOVE utilizes a 1D array, because we only care about the last row (think unique paths)
The solution BELOW utilizes the 2D array, a more classic approach to this problem. 

Where m = text1.length() and n = text2.length();
Time complexity: O(m * n). It takes m * n time to build the DP arary. Previous values 
are accessed with O(1) time. 
Space complexity: for the 1D array, it's O(min(m, n)), because we decided to make a DP array
out of the shorter string to save space. 

For below:
Time complexity: O(m * n)
Space complexity: O(m* n), entire 2D Dp array is kept. 


*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 1; i <= text1.length(); i++){
            for (int j = 1; j <= text2.length(); j++){
                
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            
            }
        }
        return dp[len1][len2];
        
    }
};