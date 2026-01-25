class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_set<int> unique;
        for(int value: arr){
            freq[value]++;

        }
       for(auto value: freq){
         unique.insert(value.second);
       }
        return unique.size() == freq.size();
    }
};
\
/*
Add the frequencies of each element into a hash map.
Then add the frequenices into a hash set. Hash set is good for this because it 
ignores duplicates. Then if both are the same size, occurrences are unique.
Time complexity: O(n) where n is the length ofht einput array.
Space complexity: O(n) to store the hash map and hash set. 
Worse case scenario is all elements are unique


*/