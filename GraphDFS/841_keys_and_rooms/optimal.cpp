class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<char> visited(n, 0);
        stack<int> st;

        visited[0] = 1;
        st.push(0);
        int count = 1;

        while (!st.empty()) {
            int room = st.top();
            st.pop();

            for (int a : rooms[room]) {
                if (!visited[a]) {
                    visited[a] = 1;
                    count++;
                    st.push(a);
                    if (count == n)
                        return true;
                }
            }
        }
        return count == n;
    }
};

// for looking up elements where we know the index,
// vector lookups are faster than hash set finds.

/*
You originally did this with unordered_set visited and keys. This worked, but it was slower because iterating
with .find() was slower than O(1) with a vector, since we know the index. 

Furthermore, having a count variable is faster than keeping keys. Count keeps track of all rooms we can visit, 
incremented when rooms are pushed onto the stack. 

Also note that ChatGPT said that vector<char> is faster than vector<bool>. Unconfirmed, 
so vector<char> visited can be replaced with vector<bool> if needed. 

*/