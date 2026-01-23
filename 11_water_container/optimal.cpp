class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int water = 0;
        while(l < r){
            water = max(water, (r-l)*min(height[l], height[r]));
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return water;
        
    }
};



/*
Important thing to realize: if h[i] == h[j],
it does not matter which one we move, the area wil always decrease.
This is because the area is found from the smaller height, so traversing to 
a higher height is inconsequential. The only thing that could happen to change the area
is iterating to an equal or smaller height, but the decreased width 
guarantees the smaller area.

Explanation: Two pointers, one starts at beginning, other at the end. 
Store the max area, and then iterate the pointer with the smaller height inwards. 
Stop when the pointers cross.

Time complexity: O(n)
Space complexity: O(1)

Takeaway: this is another example of using two pointers to optimize a brute force O(n^2) solution to O(n).


*/