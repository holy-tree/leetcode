class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int i = 0; i < strs[0].size(); i++){
            char temp = strs[0][i];
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] < temp){
                    ans++;
                    break;
                }
                temp = strs[j][i];
            }
        }
        
        return ans;
    }
};
