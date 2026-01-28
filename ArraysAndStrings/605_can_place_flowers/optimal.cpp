class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i]){continue;}
            int prev = (i == 0) ? 0 : flowerbed[i-1];
            int next = (i== flowerbed.size() - 1) ? 0 : flowerbed[i+1];

            if(!prev && !next){count++; flowerbed[i] = 1;}
        }
            
        return n <= count;
    }
};

/*
Time complexity:O(n) to iterate through the flowerbed.
Space complexity: O(1), no space beyond input used.
*/