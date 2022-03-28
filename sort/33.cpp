class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] <= target){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == target)
                    return i;
                if(nums[i] < nums[0])
                    return -1;
            }
        }

        else{
            for(int i = nums.size()-1; i >= 0; i--){
                if(nums[i] == target)
                    return i;
                if(nums[i] > nums[0])
                    return -1;
            }
        }

        return -1;
    }
};
