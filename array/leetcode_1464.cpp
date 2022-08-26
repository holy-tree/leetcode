class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);
        int a = 0;
        int b = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] >= nums[a])
                a = i;
        }
        if(a == 0)
            b++;
        for(int i = 0; i < n; i++){
            if(nums[i] >= nums[b] && i != a)
                b = i;
        }
        return (nums[a]-1)*(nums[b]-1);

    }
};
