class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num : nums) pq.push(num);
        for(int i = 1; i < k; i++ ) pq.pop();
        return pq.top();
        
    }
};
/*
Above was my first solution. Turns out it's inefficient. Each push to the pq is log n, resulting in
O(n log n) just for loading the pq. Popping k - 1 times is O(k log n), so basically O(n log n) 
for time complexity. Note that we could have used a range constructor priority_queue<int> pq(nums.begin(), nums.end())
which would take O(n) time to build.
Space complexity  is O(n).


Below is a more efficient solution. 
Use min heap so the top element is alwayst the smallest element found. 
Iterate through the rest of the elements. If it's greater than the smallest element, 
it deserves to be in the queue. Pop it and push the new element. Realize that doing this
will also reorganize the queue so the smallest element is on top again.
When we're done, we will ahve the largest k elements. This is why pq is size k:
pq.top() is the kth largest element, while the rest of the queue are the ones larger than it.

Time complexity:O(n log k), since we're procesing n-k elements.
Each push/pop takes O(log k), where k is the number of elements in the queue, and we're doing it at most n times.
Space complexity: O(k) since we're holding k elements. 


*/


class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};