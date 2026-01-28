class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int a : asteroids) {
            bool broken = false;
            while(!result.empty() && a < 0 && result.back() > 0){
                if(result.back() < -a){
                    result.pop_back();
                    continue;
                }
                else if(result.back() == -a){
                    result.pop_back();
                }
                broken = true;
                break;
            }
            if(!broken) result.push_back(a);
            
        }
        return result;
    }
};

/*
Note that only negative asteroids can collide with positive asteroids already in the stack.
Because we're evaluating from left to right, we can't have a positive asteroid collide with a negative asteroid
that comes after it. Which is why we only check for negative asteroids.

We use a continue when the current asteroid survives so that we don't set broken to true.
In the two other cases, the asteroid breaks and we end the loop.

Time complexity: O(n) where n is the length of the input array asteroids.
Space complexity: O(n) becaused worse case we store all asteroids.



*/