class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        for(int i = 2; i < size; i ++){
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[size-1], cost[size-2]);


        
    }
};

/*
Simple and elegant solution:
Every step can be reached from one or two steps below. 
Add the minimum cost of getting from either step to the current step.
Remember the final step can also be reached from one or two steps below, 
which is why the return looks like that.
Time complexity: O(n) where cost is size n. 
Space complexity: O(n) where cost is size n.
Basically, iterating through cost and saving all of the new costs
of the entire array.
*/