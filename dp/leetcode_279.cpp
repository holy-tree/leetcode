class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        int k = 1;
        for(int i = 0; i <= n; i++)
            dp[i] = i;
        while(k*k <= n){
            for(int i = 1; i <= n; i++){
                if(i >= k*k){
                    dp[i] = min(dp[i], dp[i-k*k]+1);
                }
            }
            k++;
        }
        return dp[n];
    }
};
