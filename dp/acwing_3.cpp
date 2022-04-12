#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n, v;
    cin>>n>>v;

    int volume[n];
    int value[n];
    for(int i = 0; i < n; i++)
        cin>>volume[i]>>value[i];

    int dp[v+1][n+1];
    for(int i = 0; i < v+1; i++)
        for(int j = 0; j < n+1; j++)
            dp[i][j] = 0;

    for(int i = 1; i < v+1; i++){
        for(int j = 1; j < n+1; j++){
            if(i < volume[j-1])
                dp[i][j] = dp[i][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-volume[j-1]][j] + value[j-1]);
        }
    }


    cout<<dp[v][n]<<endl;

    system("pause");
    return 0;
}
