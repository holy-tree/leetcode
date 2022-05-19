class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if(n % 2 == 1){
            long long a = 0;
            int temp = nums[nums.size()/2];
            for(int num : nums)
                a = a + max(num, temp) - min(num, temp);
            return a;
        }
        else{
            long long a = 0;
            long long b = 0;
            int temp1 = nums[nums.size()/2-1];
            int temp2 = nums[nums.size()/2];
            for(int num : nums){
                a = a + max(num, temp1) - min(num, temp1);
                b = b + max(num, temp2) - min(num, temp2);
            }
            return max(a, b);
        }
        return 0;
    }
};
