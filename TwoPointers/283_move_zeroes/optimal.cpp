class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] != 0){swap(nums[l], nums[r]); l++;}
            
        }
        
    }
};

/*
Explanation: Two pointers:
One iterates through the array. One stays at the beginning to store nonzero values.

Intuition: the r pointer finds nonzero values. The l pointer keeps track of the 
order you find them in. When you find a nonzero value, swap r and l. Then increment l.
The idea is that because l only increments after finding a nonzero value, it will always be in order.
Basically, moving all the nonzero values to the left.

Time complexity: O(n) to iterate through the array.
Space complexity: O(1), no extra space used.

*/