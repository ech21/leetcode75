class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> distinct1, distinct2;

        for(int num: set1){
            if(set2.find(num) == set2.end()) distinct1.push_back(num);
        }
        for(int num: set2){
            if(set1.find(num) == set1.end()) distinct2.push_back(num);
        }
        return{distinct1, distinct2};
        
    }
};
/*
This uses an unordered_set.
Note that the difference between unordered set and map is that
set only stores keys, while map stores key-value pairs.
Also, the difference between this and a set is that a set takes O(log n) time for search, insert, and delete operations,
while an unordered_set takes O(1) time for these operations on average.

Code is straightforward: Put the vectors into a set, and find the distinct elements between them. 

Time complexity: O(m + n) where m and n are the lengths of nums1 and nums2 respectively.
Space complexity: O(m + n) to store the sets and the output vectors.



*/