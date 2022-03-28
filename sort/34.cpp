class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        

        int l = 0;
        int r = nums.size()-1;

        int m;
        while(l <= r){
            m = (l+r) / 2;
            if(nums[m] == target){
                int left = m;
                int right = m;
                while(left-1 >= 0 && nums[left-1] == nums[m])
                    left--;
                while(right+1 < nums.size() && nums[right+1] == nums[m])
                    right++;
                
                return vector<int>{left, right};
            }
            if(nums[m] < target){
                l = m + 1;
            }
            if(nums[m] > target)
                r = m - 1;
        }

        return vector<int>{-1, -1};

    }
};
