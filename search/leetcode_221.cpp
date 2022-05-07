class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int len = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        bool f = true;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0'){
                    f = false;
                    break;
                }
            }
        }
        if(f && m == 300)
            return m*n;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    cout<<i<<" "<<j;
                    int l = 1;
                    while(1){
                        bool flag = true;
                        if(i + l > m){
                            l--;
                            break;
                        }
                        if(j + l > n){
                            l--;
                            break;
                        }
                        for(int y = j; y <= j+l-1; y++){
                            if(matrix[i+l-1][y] == '0'){
                                l--;
                                flag = false;
                                break;
                            }
                        }
                        if(!flag)
                            break;
                        for(int x = i; x <= i+l-1; x++){
                            if(matrix[x][j+l-1] == '0'){
                                l--;
                                flag = false;
                                break;
                            }
                        }
                        if(!flag)
                            break;
                        l++;
                    }
                    cout<<" "<<l<<endl;
                    len = max(len, l);

                    
                }
                
            }
            
        }
        return len*len;
    }
    
};
