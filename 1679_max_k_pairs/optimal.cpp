class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end() && mp[nums[i]] > 0) {
                mp[nums[i]]--;
                ans++;
            }
            else if(k>nums[i]) mp[k-nums[i]]++;
        }
        return ans;
    }
};
/*
Realize that this problem is actually quite similar to Two Sum (Leetcode 1).
Basically, use a hashmap to store unused complements. When a number that can use 
the complement is found, increment the count and decrement the complement count.
Note that we ONLY add complements for numbers less than k, since there's no negative numbers.

Time complexity: O(n) to iterate through the vector once.
Space complexity: O(n) in the worst case, to store all complements in the hashmap.

Using hashmaps is time efficient! But it does cost space.



*/