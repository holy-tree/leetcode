class Solution {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
        return;
    }
    void quick_sort(vector<int>& nums, int low, int high){
        int i = low;
        int j = high;
        int key = nums[low];
        while(i < j){
            while(nums[j] >= key && i < j)
                j--;
            while(nums[i] <= key && i < j)
                i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        nums[low] = nums[j];
        nums[j] = key;
        if(j-1 > low)
            quick_sort(nums, low, j-1);
        if(j+1 < high)
            quick_sort(nums, j+1, high);
    }

};
