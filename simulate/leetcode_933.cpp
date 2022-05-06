class RecentCounter {
public:
    vector<int> vt;
    RecentCounter() {
        vt.clear();
    }
    
    int ping(int t) {
        vt.push_back(t);
        int i = 0;
        while(vt[i] < t-3000)
            i++;
        return vt.size()-i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
