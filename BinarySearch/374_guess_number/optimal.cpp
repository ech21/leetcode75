/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while(low <= high){
            int guessNum = low + ((high - low) / 2);
            int g = guess(guessNum);
            if(g == -1) high = guessNum - 1;
            else if(g == 1) low = guessNum + 1;
            else return guessNum;
        }
        return low;


        
    }
};
/*
This is just a basic implementation of binary search. 
Have two pointers, one at the beginning and one at the end.
The guess should always be the middle of the current range, that is, 
low + ((high - low) / 2). 
If the guess is too high, move high to mid - 1.
If the guess is too low, move low to mid + 1. 
Iterate until the number is found, or the range converges to one number. 



*/