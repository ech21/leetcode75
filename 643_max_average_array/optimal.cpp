#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currentSum = 0;
        double maxSum = 0;
        //calculate initial window:
        for(int i = 0; i < k; i++){
            currentSum += nums[i];           
        }
        maxSum = currentSum;
        for(int i = k; i < nums.size(); i++){
            currentSum += nums[i];
            currentSum -= nums[i-k];
            maxSum = max(maxSum, currentSum);
        }
        return maxSum / k;

        
    }
};

/*
Explanation: classic sliding window.
Start by calculating the sum of the first k elements.
Then slide the window across the array by adding the next element and 
subtracting the element no longer there. 
Keep track of the maximum sum seen.
Very efficient, only one pass through the array after the initial calculation.

Time complexity: O(n), where n is the number of elements in nums.
Note that there are two passes, but k is at worst n.
Space complexity: O(1), only a few variables used.




*/