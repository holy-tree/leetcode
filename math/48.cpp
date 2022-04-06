class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int temp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                temp = matrix[j][i];
                matrix[j][i] = matrix[n-j-1][i];
                matrix[n-j-1][i] = temp;
            }
        }
       
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        return;

    }
};
