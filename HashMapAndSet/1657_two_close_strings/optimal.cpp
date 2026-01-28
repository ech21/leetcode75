class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector <int> v1(26, 0), v2(26, 0);
        
        for(char c: word1) v1[c-'a']++; 
        for(char c: word2) v2[c-'a']++; 

        for(int i=0; i<26; i++) if((v1[i]==0) != (v2[i]==0)) return 0;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for(int i=0; i<26; i++) if(v1[i]!=v2[i]) return 0;
        return 1;
    }
};

/*
The above solution is faster. Uses constant sized arrays instead of hash maps. 
The idea is to store the letters used and their frequencies. 
We don't care which letters have which frequencies, just that the sets of them are identical.
Time complexity: O(n + m) to iterate through the strings with length n and m.
Although there's a sort, the sort is on a constant sized array of size 26.
Space complexity: O(1) since the arrays are constant size. 


The below solution uses hash maps, sets, and multisets to achieve the same goal. 

*/









class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for(char c: word1) freq1[c]++;
        for(char c: word2) freq2[c]++;
        
        pair<unordered_set<char>, unordered_multiset<int>> result1;
        pair<unordered_set<char>, unordered_multiset<int>> result2;
        for(auto[c, f] : freq1){
            result1.first.insert(c);
            result1.second.insert(f);
        }
        for(auto[c, f] : freq2){
            result2.first.insert(c);
            result2.second.insert(f);
        }
        return result1 == result2;

    }
};