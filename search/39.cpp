class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(ans, candidates, path, target, 0);

        return ans;


    }

    void dfs(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& path, int sum, int last){

        if(sum == 0){
            ans.push_back(path);
            return;
        }

        for(int cand : candidates){
            if(cand < last){
                continue;
            }
            if(cand > sum)
                continue;

            vector<int> newpath = path;
            newpath.push_back(cand);

            dfs(ans, candidates, newpath, sum-cand, cand);
        }


    }

};
