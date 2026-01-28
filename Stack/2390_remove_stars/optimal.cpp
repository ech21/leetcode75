class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(char c : s){
            if(c != '*') st.push(c);
            else st.pop();
        }
        string result(st.size(), ' ');
        for (int i = result.size() - 1; i >= 0; i --){
            result[i] = st.top();
            st.pop();

        }
        return result;

        
    }
};




/*
Typical stack usage. 
The most recently seen character is the one that's removed as we iterate.
We remove it by popping it, and characters are added via push.
Then we build the final string from the stack. 
Time compelexity: O(n) where n is the length of the input string s.
Space complexity: O(n) for the string at worst case length n.

Below is a pseudo-stack usage, where the string itself acts as a stack. This way, 
we don't need to recreate the string.

*/

class Solution {
public:
    string removeStars(string s) {
        string c="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                c.pop_back();
            }else{
                c+=s[i];
            }
            
        }
        return c;
    }
};