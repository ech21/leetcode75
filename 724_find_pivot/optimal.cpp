class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int i : nums){
            totalSum += i;
        }
        int whatsLeft = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(whatsLeft == totalSum - whatsLeft - nums[i]) return i;
            whatsLeft += nums[i];
        }
        return -1;
        
    }
};

/*
The solution above is optimal.

Barely requries a prefix sum array. After calculating the total sum, 
we can keep track of the right sum by subtracting left sum and current element from the total.
When they equate, return the pivot index.

Time complexity: O(n) where n is the length of the input array. 
The input array is traversed twice.
Space complexity: O(1), no output or extra space is used.
-------------------------------------------------------------------------
The solution below mimics problem 238 by having the two passes.

Time complexity: O(n) to traverse the input array twice. 
HOWEVER:
Space complexity:O(n) to store the vectors leftpass and rightpass.
So while you saw this problem as similar to 238, this is not an optimal solution.

*/


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftpass(nums.size(), 0);
        vector<int> rightpass(nums.size(), 0);
        int left = 0;
        int right = 0;
      
        for(int i = nums.size() - 1; i >= 0; i --){
            rightpass[i] = right;
            right += nums[i];
        }
        for(int i = 0; i < nums.size(); i ++){
            leftpass[i] = left;
            left += nums[i];
            if(leftpass[i] == rightpass[i]){return i;}
        }
        return -1;
        
    }
};