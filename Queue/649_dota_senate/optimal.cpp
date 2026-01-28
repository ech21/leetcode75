class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dir;
        int n = senate.length();
        for (int i = 0; i < n; i ++){
            if(senate[i] == 'R') rad.push(i);
            else dir.push(i);
        }
        while(!rad.empty() && !dir.empty()){
            if(rad.front() < dir.front())rad.push(n++);
            else dir.push(n++);
            rad.pop();
            dir.pop();
            
        }
        return(rad.empty() ? "Dire" : "Radiant");
        
    }
};

/*
Each senator gets put in a queue of their own party.
We process the queues until one is empty.
In each iteration, compare the front of the queue. The person
with the lower index wins and rejoins the queue. The other is just popped.

The queue that stays nonempty is the winner.

Time complexity: O(n) where n is the length of the input string. 
Space complexity: O(n) for the two queues.


*/