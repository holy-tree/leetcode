class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        if(n < 2)   
            return s;
        
        //dp[i][j] = true表示字串s(i~j)为回文子串  
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i = 0; i < n; i++)
            dp[i][i] = true;

        int len = 1;
        int begin = 0;

        for(int l = 1; l < n; l++){
            for(int i = 0; i < n; i++){
                int j = i + l;

                if(j >= n){
                    break;
                }

                if(s[i] == s[j]){
                    if(j - i < 3){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }

                }

                else{
                    dp[i][j] = false;
                }

                if(dp[i][j] == true){
                    if(j-i+1 > len){
                        len = j-i+1;
                        begin = i;
                    }
                }

            }
        }

        return s.substr(begin, len);
    }
};
