class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[nums.size()/2] == nums[nums.size()/2-1])    
            return nums[nums.size()/2];
        else{
            if(nums[0] == nums[nums.size()/2-1])
                return nums[nums.size()/2-1];
            else
                return nums[nums.size()/2];
        }
        return 0;
    }
};
