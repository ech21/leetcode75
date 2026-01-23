class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int n : nums){
            if(n <= min1){min1 = n;}
            else if(n <= min2){min2 = n;}
            else{return true;}
        }
        return false;
    }
};

/*
Explanation: Keeping states. min1 is always the smallest number found so far. If min1's
if statement passes, it means the numbers are decreasing, so update min1. 
If min2's if statement passes, we have found the second smallest number, so store it.
If BOTH statements fail, it means we have found a number larger than min1 and min2. 
Thus we have found the increasing triplet, and return true. 

The intuition to gain is that we are replacing brute force with maintaining states.
This means we don't need to compare every number with every other number.

Time Complexity: O(n) to iterate through the array once.
Space complexity: O(1):no output storage and no extra space!








www
*/