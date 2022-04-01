class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        // vector<vector<int>> ans;
        // vector<int> med;

        // backtrace(ans, nums, med);

        // return ans;

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        do{
            ans.push_back(nums);
        }
        while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
    // void backtrace(vector<vector<int>>& ans, vector<int>& nums, vector<int>& med){

    //     if(med.size() == nums.size()){
    //         ans.push_back(med);
    //         return;
    //     }

    //     for(int i : nums){
    //         if(find(med.begin(), med.end(), i) == med.end()){
    //             vector<int> newmed = med;
    //             newmed.push_back(i);
    //             backtrace(ans, nums, newmed);
    //         }
    //     }
    // }
};
