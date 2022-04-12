#include<iostream>

using namespace std;

int main(){

    int n, v;
    cin>>n>>v;

    int volume[n];
    int value[n];
    int number[n];

    for(int i = 0; i < n; i++)
        cin>>volume[i]>>value[i]>>number[i];

    int dp[v+1][n+1];
    for(int i = 0; i < v+1; i++)
        for(int j = 0; j < n+1; j++)
            dp[i][j] = 0;

    for(int i = 1; i < v+1; i++){
        for(int j = 1; j < n+1; j++){
            int temp = dp[i][j-1];
            for(int k = 1; k <= number[j-1]; k++){
                if(i < k*volume[j-1])
                    break;
                temp = max(temp, dp[i-k*volume[j-1]][j-1] + k*value[j-1]);
            }
            dp[i][j] = temp;
        }
    }

 
            

    cout<<dp[v][n]<<endl;


    system("pause");
    return 0;
}
