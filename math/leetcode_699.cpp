class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int left1 = positions[i][0];
            int right1 = positions[i][0] + positions[i][1] - 1;
            ans[i] = positions[i][1];
            for(int j = 0; j < i; j++){
                int left2 = positions[j][0];
                int right2 = positions[j][0] + positions[j][1] - 1;
                if(right1 >= left2 && right2 >= left1)
                     ans[i] = max(ans[i], ans[j] + positions[i][1]);
            }
        }
        for(int i = 1; i < n; i++)
            ans[i] = max(ans[i], ans[i-1]);
        return ans;
    }
};
