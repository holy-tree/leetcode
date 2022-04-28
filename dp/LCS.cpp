#include<bits/stdc++.h>

using namespace std;


int main()
{
    string x = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD";
    string y = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG";
    int n = x.length();
    int m = y.length();
    
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = 0;

    int substring = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                substring = max(substring, dp[i][j]);
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // dp[i][j] = 0;
            }
        }
    }
    
    cout<<substring<<endl;


    system("pause");
    return 0;
}
