#include<bits/stdc++.h>

using namespace std;

int main()
{   
    int n = 6;
    int m[n+1] = {30, 35, 15, 5, 10, 20, 25};

    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    // string route[n][n];
    
    for(int r = 1; r < n; r++){
        for(int i = 0; i < n-r; i++){
            int j = i + r;

            // for(int s = i; s <= j; s++){
            //     route[i][j] = route[i][j] + "A" + to_string(s);
            // }

            int mincal = dp[i][i] + dp[i+1][j] + m[i]*m[j+1]*m[i+1];
            int index = 0;
            for(int k = i+1; k <= j; k++){
                int cal = dp[i][k-1] + dp[k][j] + m[i]*m[j+1]*m[k];
                if(cal < mincal){
                    mincal = cal;
                    index = k;
                }
            }

            dp[i][j] = mincal;

            // int index1;
            // for(int ii = 0; ii < route[i][j].size(); ii++){
            //     if(route[i][j][ii] == to_string(2*index)[0])
            //         index1 = ii-1;
            // }
            // route[i][j].insert(index1, ")(");
            // route[i][j].insert(0, "(");
            // route[i][j].append(")");

        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%8d", dp[i][j]);
        }
        cout<<endl;
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         printf("%16s", route[i][j].c_str());
    //     }
    //     cout<<endl;
    // }


    system("pause");
    return 0;
}
