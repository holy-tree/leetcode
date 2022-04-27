class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        bool dp[s.length()+1];
        dp[0] = true;
        
        for(int i = 1; i <= s.length(); i++){
            string str = s.substr(0, i);
            for(int j = str.length(); j > 0; j--){
                bool after = false;
                for(string &sss : wordDict){
                    if(sss == str.substr(0+j-1)){
                        after = true;
                    }
                }
                after = after && dp[j-1];
                if(after == true){
                    dp[i] = true;
                    break;
                }
                dp[i] = false;
            }
        }
        return dp[s.length()];
        
        
        // int ans = false;
        // for(string &str : wordDict){
        //     if(s.size() >= str.size()){
        //         string pres = s;
        //         if(pres.assign(pres, 0, str.length()) == str){
        //             // cout<<pres<<endl;
        //             string temp = s;
        //             temp.assign(temp, str.length(), temp.length()-str.length());
        //             // cout<<temp<<endl;
        //             if(temp.length() == 0)
        //                 return true;
        //             ans = ans || wordBreak(temp, wordDict);
        //         }
                
        //     }
        // }
        // return ans;
    }
    
};
