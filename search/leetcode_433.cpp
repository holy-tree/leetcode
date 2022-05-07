class Solution {
public:
    int ans = 1000;
    int minMutation(string start, string end, vector<string>& bank) {
        if(find(bank.begin(), bank.end(), end) == bank.end())
            return -1;
        vector<bool> flag(bank.size(), true);
        backtrace(start, end, bank, flag, 0);
        if(ans == 1000)
            return -1;
        return ans;        
    }
    void backtrace(string start, string end, vector<string>& bank, vector<bool>& flag, int count){
        if(start == end){
            ans = min(ans, count);
            return;
        }
        for(int i = 0; i < bank.size(); i++){
            if(diff(bank[i], start) && flag[i]){
                
                flag[i] = false;
                backtrace(bank[i], end, bank, flag, count+1);
                flag[i] = true;
                
            }
        }
        return;
    }
    bool diff(string str1, string str2){
        int count = 0; 
        for(int i = 0; i < 8; i++){
            if(str1[i] != str2[i])
                count++;
            if(count > 1)
                return false;
        }
        if(count == 1)
            return true;
        return false;
    }
};
