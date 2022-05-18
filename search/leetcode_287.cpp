class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        for(int num : nums){
            if(st.count(num) == 1)
                return num;
            st.insert(num);
        }
        return 0;
    }
};
