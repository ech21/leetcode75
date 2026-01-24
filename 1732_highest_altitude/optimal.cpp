class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int sum = 0;
        vector<int> alt = {0};
        for (int g : gain){
            sum += g;
            alt.push_back(sum);
        }
        return *max_element(alt.begin(), alt.end());
        
    }
};
/*
A prefix sum array is where each element at index i is the sum of all elements
up to index i in the original array. That is, prefix[i] = arr[0] + arr[1]... + arr[i].
Very easy way to find cumulative sums. You might remember doing this in leetcode 238, 
where we used prefix products instead of sums.

Note that max_element returns an iterator to the maximum element, 
which is the reason for the dereferencing.


Time complexity: O(n) where n is the length of gain.
Space complexity: O(n) to store the prefix array named alt.


*/