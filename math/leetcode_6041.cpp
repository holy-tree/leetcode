class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        // int index = 0;
        for(int i = 0; i < nums.size(); i++){
            sort(nums[i].begin(), nums[i].end());
            // if(nums[i].size() < nums[index].size())
            //     index = i;
        }
        int numsi[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            numsi[i] = 0;
        
        for(int i = 0; i < nums[0].size(); i++){
            bool flag = true;
            for(int j = 0; j < nums.size(); j++){
                while(nums[j][numsi[j]] < nums[0][i] && numsi[j] < nums[j].size()-1)
                    numsi[j]++;
                if(nums[j][numsi[j]] != nums[0][i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                ans.push_back(nums[0][i]);
        }
        return ans;
        
        
    }
};
