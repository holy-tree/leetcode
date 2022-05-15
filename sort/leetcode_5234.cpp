class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        if(n == 1)
            return words;
        string s1;
        string s2;
        for(int i = 1; i < words.size();){
            s1 = words[i-1];
            s2 = words[i];
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            if(s1 == s2){
                words.erase(words.begin() + i);
            }
            else{
                i++;
            }
            if(i == words.size())
                break;
        }
        return words;
    }
};
