class RecentCounter {
public:
    RecentCounter() : start(0){
        
    }
    
    int ping(int t) {
        records.push_back(t);
        while(records[start] < t - 3000){
            start++;
        }
        return records.size() - start;
    }
private:
    std::vector<int> records;
    int start;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

 /*
 Standard class initialization with constructor.
 Remember your initializer lists!
 In ping, we add the new time t to records.
 Then we increment start until the time at records[start] is 
 outside the 3000ms window.
 Finally return the number of pings within the window.
 
 
 
 
 */