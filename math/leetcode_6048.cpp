class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, vector<int>> m;
        for(int i = 0; i < cards.size(); i++){
            auto it = m.find(cards[i]);
            if(it == m.end()){
                m.insert(pair<int, vector<int>>(cards[i], vector<int>{i, 1000000}));
            }
            else{
                it->second[1] = min(it->second[1], i-it->second[0]+1);
                it->second[0] = i;
            }
        }
        int ans = 1000000;
        for(auto it = m.begin(); it != m.end(); it++){
            ans = min(ans, it->second[1]);
        }
        
        if(ans == 1000000)
            return -1;
        return ans;
    }
};
