#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        std::vector<bool>result(candies.size());
        for(int i = 0; i < candies.size(); i++ ){
            result[i] = extraCandies + candies[i] >= max;
        }
        return result;
        
    }
};

/*
Algorithm explanation: Find the max, then check if each kid + extraCandies >= max. 
If yes, set true, else false, return the vector. 
Time complexity: O(n) to find max, O(n) to iterate through candies, total O(n).
Space complexity: O(n) to store result vector.
*/

//Alternate way: using push_back
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int maxCandies = 0;
       vector<bool> result;
       for (int candy : candies){
            maxCandies = max(maxCandies, candy);
       }
       for (int candy: candies){
            result.push_back(candy + extraCandies >= maxCandies);
       }
       return result;
    }
};
