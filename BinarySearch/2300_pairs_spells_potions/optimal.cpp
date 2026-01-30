class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> result;
    int n = potions.size();
    for(int spell: spells){
        //int remainder = success / spell;
        int idx = binary(spell, potions, success);
        
        result.push_back(potions.size() - idx);
    }
    return result;
        
    }
    int binary(int spell, vector<int>& potions, long long success){
        int low = 0;
        int high = potions.size() - 1;
        if((long long)spell * potions[high] < success) return potions.size();
        if((long long)spell * potions[low] >= success) return 0;
        int idx = potions.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if((long long) spell * potions[mid] >= success){
                idx = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return idx;
    }
};
/*
Another typical Binary Search, this time searching for indices.
The search returns the lowest valid index, so the result is the size of the array - binary search result.
Time complexity: O(m log m) to sort the potions array, 
then we binary search through it n times for n * log m. 
Total time complexity is O(m log m + n log m).
Space complexity: O(n) to hold the result array. 

*/