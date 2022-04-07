class Solution {
public:
    bool canJump(vector<int>& nums) {
        int barrier = 0;
        for(int i = 0; i <= barrier; i++){
            barrier = max(barrier, i + nums[i]);
            if(barrier >= nums.size()-1)
                return true;
        }
        return false;
    }
};
