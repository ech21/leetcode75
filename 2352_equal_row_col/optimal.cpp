class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int result = 0;
        map<vector<int>, int> rows, cols;
        for(int i = 0; i < grid.size(); i ++){
            rows[grid[i]]++;
            vector<int> col;
            for(int j = 0; j<grid.size(); j ++) col.push_back(grid[j][i]);
            cols[col]++;
        }
        for(auto row : rows){
            if(cols.find(row.first) != cols.end()){
                result += row.second * cols[row.first];
            }
        }
        return result;

    }
};

/*
Explanation: One map for rows, one for columns.
The rows are already in their vector forms, add them by frequency to the rows map.
The cols need to be constructed as vector, then added to the cols map by frequency.
Finally, iterate through the rows map. If a vector is also in the cols map, 
add the product of the two frequencies. This is because the frequency counts each 
row/col that matches, and each row can match with each col separately (combinatorics).

Time complexity: Comes in multiple parts:
O(n^2) to iterate through the grid to build the rows and cols maps.
O(n log n) because it costs O(log n) to insert into the map, and
because the key is a vector of size n, it costs O(n) to compare keys.
> How map insertion works: a map is a balanced binary search tree. It looks for keys
> by comparing them. On average, it will take O(log n) comparison to find the right spot.
> However, because these are vectors, the comparisons themselves take O(N) time.
So overall, because there's a map insertion inside the nested for loop, it costs
O(n^2 * n * log n) = O(n^3 log n)

Space complexity: O(n^2) to store the rows and cols maps.


*/