class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> st(nums.begin(), nums.end());
        nums.assign(st.begin(), st.end());
        int ans = 0;
        int i = 0;
        int len = 0;
        while(i < nums.size()){
            if(len == 0)
                len++;
            if(i > 0){
                if(nums[i] == nums[i-1] + 1){
                    len++;
                }
                else
                    len = 1;
            }
            ans = max(ans, len);
            i++;
        }
        return ans;
    }
};
