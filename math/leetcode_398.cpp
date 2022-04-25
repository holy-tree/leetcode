class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target)
                temp.push_back(i);
        }
        // cout<<temp.size()<<" "<<temp[0]<<temp[1]<<temp[2]<<endl;
        // srand((int)time(NULL));
        return temp[rand()%temp.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
