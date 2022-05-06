class Solution {
public:
    int majorityElement(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        for(int i : st){
            if(count(nums.begin(), nums.end(), i) > nums.size()/2)
                return i;
        }
        return 0;
    }
};
