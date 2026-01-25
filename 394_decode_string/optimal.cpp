class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch : s){
            if(ch==']'){
                string stringToRepeat;
                while(!st.empty() && st.top() != "["){
                    stringToRepeat += st.top();
                    st.pop();
                }
                st.pop();
                string multiplier;
                while(!st.empty() && isdigit(st.top()[0])){
                    multiplier += st.top();
                    st.pop();
                }
                reverse(multiplier.begin(), multiplier.end());
                int n = stoi(multiplier);
                string current;
                while(n--){
                    current += stringToRepeat;
                }
                st.push(current);

            }
            else{
                string temp(1, ch);
                st.push(temp);
            }
        }
        string result;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};

/*
Simply: 
Whenever we see ] (implying the end of a bracketed string)
Pop from the stack to find the string to be repeated.
Pop again to remove the [
Pop again to find the multiplier, which could be multiple digits, requiring 
reversal and conversion to integer.
Then, create the string current, which is the stringToRepeat repeated n times.
Push current back onto the stack.
Finally, pop the elements and reverse for the final string. 
note: normal strings with no brackets work, because we only look for brackets
once the closing bracket is found, which is the last part of the encoded string.

Time complexity:O(n + m) where n is the length of the input string s and m is the length of the longest intermediate string.




*/