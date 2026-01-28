class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>lastrow(n, 1);
        int up = 0, left = 0;
        for(int r = 1; r < m; r++){
            for(int c = 1; c< n; c++){
                left = lastrow[c-1];
                up = lastrow[c];
                lastrow[c] = left+up;
            }
        }
        return lastrow[n-1];
        
    }
};

/*
While this question was trying to test for multidimensional DP, there is a simpler solution. 
First, realize that the number of unique ways to get to a certain tile is:
uniqueWays = uniquePathsFromLeft + uniquePathsFromTop.
Vector lastRow is our memoization. It keeps track of the unique paths for the last row.
First, realize that the left column always has unique paths of 1. This is why c[0] is left untouched.
Also realize the top row always has unique paths of 1. This is why the vector is initialized to 1.
Now, to calculate: uniquePathsFromLeft comes from lastRow[c-1], and uniquePathsFromTop comes from lastRow[c]. 
Imagine it as each element of lastRow "coming down" to the next row once it's been recalculated.
Return lastRow's last element (the destination) once we're all done.

Time complexity: O(m * n)
Space complexity: O(n)

But just in case, here's a 2D DP solution.
Time complexity: O(m * n)
Space complexity O(m * n)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        dp[0][0] = 1;
        int up = 0;
        int left = 0;
        
        for( int r= 0; r<m; r++ ){
            for( int c= 0; c<n; c++ ){
                if( r==0 && c==0 ){
                    continue;
                }
                up = 0;
                left = 0;

                if( c>=1 ){
                    left = dp[r][c-1];
                }

                if( r>=1 ){
                    up = dp[r-1][c];
                }

                dp[r][c] = left + up;
            }
        }
        return dp[m-1][n-1];
    }
};