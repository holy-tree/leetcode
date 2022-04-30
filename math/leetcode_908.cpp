class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int a = (nums[nums.size()-1]-nums[0]) - 2*k;
        return a > 0 ? a : 0; 
    }
};
