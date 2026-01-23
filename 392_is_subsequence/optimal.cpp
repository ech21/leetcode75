class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0;
        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[sp]){
                sp++;
            }
        }
        if (sp == s.size()){return true;}
        return false;
        
    }
};

/*
Expalantion: Two pointers. One iterates through t, the other through s.
When characters match, increment the s pointer. If the s pointer reaches the end, 
we have found all the characters in order, so return true.

Realize that it guarantees order because we only increment the s pointer after finding the previous.

Time complexity: O(n) where n is the length of t. 
Space complexity: O(1), no space used for output or otherwise.



*/