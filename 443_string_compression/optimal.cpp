class Solution {
public:
    int compress(vector<char>& chars) {
        int result = 0;
        for(int pointer = 0; pointer < chars.size();){
            char letter = chars[pointer];
            
            int count = 0;

            while(pointer < chars.size() && chars[pointer] == letter  ){ //ORDER MATTERS BECAUSE OF SHORT CIRCUIT
                pointer++;
                count++;
            }
            chars[result++] = letter;
            if (count > 1){
                for(char c : to_string(count)){
                    chars[result++] = c;
                }
            }

        }
        return result;

        
        
    }
};

/*
Explanation: Two pointers: one to iterate through the array and one to store the result.
The result pointer only moves to store a character in the chars array.
The pointer pointer moves to find the consecutive vowels.
Time complexity: O(n) where n is the length of the input array.
Space complexity: O(1) since we are modifying the input array in place.

KEY TAKEAWAYS:
1. This was actually pretty easy. Don't be afraid to just...try
2. Read the problem statement carefully. It says ignore elements after the new length.
3. Looking at line 10: an issue with short circuiting. If pointer is out of bounds,
   then chars[pointer] will throw an error. So we have to check pointer < chars.size() first.
4. A for loop doesn't have to increment by 1 each time. You can control the pointer however you want.
*/