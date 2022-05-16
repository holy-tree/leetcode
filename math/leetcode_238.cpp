class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre{nums[0]};
        vector<int> suf{nums[n-1]};
        for(int i = 1; i < n; i++)
            pre.push_back(pre[i-1] * nums[i]);
        for(int i = n-2; i >= 0; i--)
            suf.push_back(suf[n-i-2] * nums[i]);
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(i-1 < 0)
                ans.push_back(suf[n-i-2]);
            else if(n-i-2 < 0)
                ans.push_back(pre[i-1]);
            else
                ans.push_back(pre[i-1] * suf[n-i-2]);
        }

        return ans;
    }
};
