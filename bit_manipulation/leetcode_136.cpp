class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int, int> p;
        // for(int i : nums){
        //     if(p.find(i) == p.end()){
        //         p.insert(pair<int, int>(i, 1));
        //     }
        //     else
        //         p[i]++;
        // }
        // for(auto &i : p){
        //     if(i.second == 1)
        //         return i.first;
        // }
        // return 0;
        int ans = 0;
        for(int i : nums)
            ans = ans ^ i;
        return ans;
    }
};
