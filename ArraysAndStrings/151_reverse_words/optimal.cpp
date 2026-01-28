#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
      
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss >> word){
            words.push_back(word);
        }
        string result;
        for (int i = words.size() - 1; i >= 0; i--){
            result += words[i];
            if(i != 0){
                result += ' ';
            }
        }
        return result;
        


        
    }
};

/*
Explanation: Use stringstream to split the input string into words. When extracting words
from the stringstream, it automatically handles multiple spaces and trims leading/trailing spaces.
Store the words in a vector, then iterate the vector backwards to construct the result string,
adding a space between words except for the last one.

Time complexity: O(n) where n is the length of the input string.
Space complexity: O(n) to store the words in a vector



*/