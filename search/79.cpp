class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // int flag[m][n];
        vector<vector<int>> flag(m, vector<int>(n));

        // for(int i = 0; i < m; i++)
        //     for(int j = 0; j < n; j++)
        //         flag[i][j] = 0;

        // stack<pair<int, int>> st;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                


                if(board[i][j] == word[0]){
                    for(int i = 0; i < m; i++)
                        for(int j = 0; j < n; j++)
                            flag[i][j] = 0;


                    flag[i][j] = 1;
                    if(word.size() == 1)
                        return true;
                    if(dfs(board, flag, i, j, word, 1))
                        return true;
                }


                




                // if(board[i][j] == word[0]){
                //     int index = 1;
                //     if(index == word.size())
                //         return true;
                //     st.push(pair<int, int>(i, j));
                //     flag[i][j] = 1;

                //     bool free = false;
                //     vector<pair<int, int>> freevec;

                //     while(!st.empty()){
                //         int x = st.top().first;
                //         int y = st.top().second;
                //         cout<<x<<" "<<y<<endl;
                //         if(x > 0 && board[x-1][y] == word[index] && flag[x-1][y] == 0){
                //             st.push(pair<int, int>(x-1, y));
                //             flag[x-1][y] = 1;
                //         }
                //         else if(x < m-1 && board[x+1][y] == word[index] && flag[x+1][y] == 0){
                //             st.push(pair<int, int>(x+1, y));
                //             flag[x+1][y] = 1;
                //         }
                //         else if(y > 0 && board[x][y-1] == word[index] && flag[x][y-1] == 0){
                //             st.push(pair<int, int>(x, y-1));
                //             flag[x][y-1] = 1;
                //         }
                //         else if(y < n-1 && board[x][y+1] == word[index] && flag[x][y+1] == 0){
                //             st.push(pair<int, int>(x, y+1));
                //             flag[x][y+1] = 1;
                //         }
                //         else{
                //             free = true;
                //             freevec.push_back(pair<int, int>(st.top().first, st.top().second));
                //             st.pop();
                //             index--;
                //             continue;
                //         }
                //         if(free == true){
                //             free = false;
                //             for(auto it : freevec){
                //                 flag[it.first][it.second] = 0;
                //             }
                //             freevec.clear();
                //         }
                //         index++;
                //         if(index == word.size()){
                //             return true;
                //         }
                //     }
                //     for(int i = 0; i < m; i++)
                //         for(int j = 0; j < n; j++)
                //             flag[i][j] = 0;
                // }


            
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& flag, int i, int j, string word, int index){
        if(index == word.size())
            return true;
        if(i > 0 && board[i-1][j] == word[index] && flag[i-1][j] == 0){
            flag[i-1][j] = 1;
            if(dfs(board, flag, i-1, j, word, index+1))
                return true;
        }
        if(i < board.size()-1 && board[i+1][j] == word[index] && flag[i+1][j] == 0){
            flag[i+1][j] = 1;
            if(dfs(board, flag, i+1, j, word, index+1))
                return true;
        }
        if(j > 0 && board[i][j-1] == word[index] && flag[i][j-1] == 0){
            flag[i][j-1] = 1;
            if(dfs(board, flag, i, j-1, word, index+1))
                return true;
        }
        if(j < board[0].size()-1 && board[i][j+1] == word[index] && flag[i][j+1] == 0){
            flag[i][j+1] = 1;
            if(dfs(board, flag, i, j+1, word, index+1))
                return true;
        }
        flag[i][j] = 0;
        return false;
    }

};
