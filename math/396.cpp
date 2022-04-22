class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            ans = ans + i * nums[i];
            sum = sum + nums[i];
        }

        int temp = ans;
        for(int i = n-1; i > 0; i--){
            temp = temp + sum - n * nums[i];
            ans = max(ans, temp);
        }

        return ans;

    }
};
