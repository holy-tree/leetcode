class Solution {
public:
    bool flag = false;
    int maxProduct(vector<int>& nums) {
        int ans = submaxProduct(nums, 0, nums.size()-1);
        if(flag)
            return max(ans, 0);
        return ans;
    }
    int submaxProduct(vector<int>& nums, int left, int right){
        if(left == right)
            return nums[left];
        for(int i = left; i <= right; i++){
            if(nums[i] == 0){
                flag = true;
                if(i == left)
                    return submaxProduct(nums, i+1, right);
                if(i == right)
                    return submaxProduct(nums, left, i-1);
    
                return max(submaxProduct(nums, left, i-1), submaxProduct(nums, i+1, right));        
            }
        }
        int product = 1;
        for(int i = left; i <= right; i++){
            product *= nums[i];
        }
        if(product > 0)
            return product;
        else{
            int temp = nums[left];
            for(int i = left; i <= right; i++){
                if(nums[i] < 0){
                    if(i == left)
                        temp = max(temp, submaxProduct(nums, i+1, right));
                    else if(i == right)
                        temp = max(temp, submaxProduct(nums, left, i-1));
                    else{
                        temp = max(submaxProduct(nums, left, i-1), temp);   
                        temp = max(submaxProduct(nums, i+1, right), temp);
                    }
                }
            }
            return temp;
        }
        return 0;
    }
};
