class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);
        int index = 0;
        for(vector<int> v : intervals){
            if(v[0] <= ans[index][1] && v[1] >= ans[index][1]){
                ans[index][1] = v[1];
            }
            else if (v[0] > ans[index][1]){
                ans.push_back(v);
                index++;
            }
        }
        return ans;

    }
};
