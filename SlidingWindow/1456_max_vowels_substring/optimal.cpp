class Solution {
public:
    int maxVowels(string s, int k) {
        string substring = s.substr(0, k);
        string vowels = "aeiou";
        int maxVowels = 0;
        for (char c : substring){
            if (vowels.find(c) != string::npos){
                maxVowels++;
            }
        }
        int count = maxVowels; //Remember, maxVowels keeps track of the MAX, not the LAST WINDOW.
        for(int i = k; i < s.size(); i++){
            if (vowels.find(s[i]) != string::npos) count++;
            if (vowels.find(s[i-k]) != string::npos) count--;
            maxVowels = max(count, maxVowels);
        }
        return maxVowels;


    }
};

/*
Standard shifting window. Start with initial count, then 
shift the window, adding/deleting vowels. Keep track of the max vowels.

Time complexity:O(n), where n is the length of the string s.
Space complexity: O(1), only a few variables used. 

Below is an alternate way that uses one for loop instead of two. 
The initial calculation is combined with the rest of the loop.

*/

class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int maxVowels = 0;
        int count = 0; 
        for(int i = 0; i < s.size(); i++){
            if (vowels.find(s[i]) != string::npos) count++;
            if ((i>=k) && vowels.find(s[i-k]) != string::npos) count--;
            //Again: Remember short circuiting in C++
            //i>=k must be checked first, otherwise s[i-k] may be out of bounds
            maxVowels = max(count, maxVowels);
        }
        return maxVowels;


    }
};