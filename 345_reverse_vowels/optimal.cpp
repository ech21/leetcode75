class Solution {
public:
    string reverseVowels(string s) {
        string result = s;
        int left = 0;
        int right = s.length() - 1;
        string vowels = "aeiouAEIOU";
        while(left < right){
            while(left < right && vowels.find(result[left]) == string::npos){
                left++;
            }
            while(left < right && vowels.find(result[right]) == string::npos){
                right--;
            }
            swap(result[left], result[right]);
            left++;
            right--;


        }
        return result;
    }
};

/*
Explanation: Use two pointers, one starting from the left and the other from the right.
Move them closer to the center until they both point at a vowel. Swap those values, 
then keep going.

Time complexity: O(n) where n in the length of the input string.
Space complexity: O(n) to store the result string.

*/