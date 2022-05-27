class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int ans = n;
        int index1 = 2*n;
        int index2 = n;
        for(int i = 0; i < n; i++){
            if(words[i] == word1){
                index1 = i;
                ans = min(ans, abs(index1-index2));
            }
            if(words[i] == word2){
                index2 = i;
                ans = min(ans, abs(index1-index2));
            }
        }
        return ans;
    }
};
