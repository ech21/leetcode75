class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int left = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            result[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            result[i] *= right;
            right *= nums[i];

        }
        return result;

    }
};

/*
Algorithm explanation: Use two passes. First pass calculates products left of element, second pass calculates the right. 
Multiply them together for the final result. 

Key takeaway: You don't have to calculate each result one at a time. If there is a PATTERN of operations among the inputs, 
you can break it down into multiple operations in separate passes. This reduces time complexity.

Time complexity: O(n) where n is the length of the input array. The input array is traversed twice. 
Space complexity: O(n) to store the result array. No auxiliary space is used. 

*/