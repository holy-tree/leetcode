class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        for(int i = 0; i < nums.size(); i++){
            int t = 0;
            vector<int> temp;
            for(int j = i; j < nums.size(); j++){
                if(nums[j] % p == 0)
                    t++;
                if(t > k)
                    break;
                temp.push_back(nums[j]);
                st.insert(temp);
            }
        }
        return st.size();
    }
};
