class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), true));
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                flag[i][j] = true;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && flag[i][j] == true){
                    dfs(grid, flag, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& flag, int i, int j){
        if(i < 0 || i == grid.size() || j < 0 || j > grid[0].size())
            return;
        grid[i][j] = false;
        if(i != grid.size()-1 && grid[i+1][j] == '1' && flag[i+1][j] == true)
            dfs(grid, flag, i+1, j);
        if(i > 0 && grid[i-1][j] == '1' && flag[i-1][j] == true)
            dfs(grid, flag, i-1, j);
        if(j != grid[0].size()-1 && grid[i][j+1] == '1' && flag[i][j+1] == true)
            dfs(grid, flag, i, j+1);
        if(j > 0 && grid[i][j-1] == '1' && flag[i][j-1] == true)
            dfs(grid, flag, i, j-1);
        
        
    }
};
