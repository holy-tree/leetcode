class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> temp;

        ans.push_back(temp);

        sort(nums.begin(), nums.end());

        trace_back(ans, nums, temp, 0);

        return ans;

    }

    void trace_back(vector<vector<int>>& ans, vector<int>& nums, vector<int>& last, int index){
        for(int i = index; i < nums.size(); i++){
            vector<int> newvec = last;
            newvec.push_back(nums[i]);
            ans.push_back(newvec);
            if(i != nums.size()-1)
                trace_back(ans, nums, newvec, i+1);
        }
    }

};
