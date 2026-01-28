class SmallestInfiniteSet {
public:
    int current;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> added;

    SmallestInfiniteSet() {
        current = 1;
        
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int smallest = pq.top();
            pq.pop();
            added.erase(smallest);
            return smallest;
        }
        return current++;
    }
    
    void addBack(int num) {
        if(num < current && added.find(num) == added.end()){
            pq.push(num);
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

 /*
 Realize that this entire thing only cares about the smallest number in the set
 at all times. Nothing else.
 current keeps track of the "regular" set that we started with. The pq keeps track of any numbers
 that are added after some numbers are removed that are smaller than current. 
 Imagine current = 5, and then 3 gets added back. 3 gets added back to the pq, and if 
 someone pops, it'll return 3. If another pop happens, it'll return 5, or if another 
 push happens, it'll be in the pq. 
 
 current++ is called post-increment syntax: after current is accessed, it increments it by 1.
 That's how we can increase current after it returns its present value. 
 
 Time complexity: O(log k), where k is the number of elements added back. 
 This is because pq.pop() and pq.push() are O(log k )

 Space complexity: O(k) where k is the number of elements added back. 
 
 */