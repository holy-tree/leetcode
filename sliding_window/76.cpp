class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> hash;
        for(char c : t){
            if(hash.find(c) == hash.end()){
                hash.insert(pair<char, int>(c, 1));
            }
            else
                hash[c]++;
        }
        int i = 0;
        int j = 0;
        string ans;
        int len = s.size();
        while(hash.find(s[i]) == hash.end() && i != s.size()-1)
            i++;
        
        j = i;
        hash[s[i]]--;
       
        while(i <= s.size()){
            while(j <= s.size()){
                if(iscorrect(hash)){
                    if(j - i + 1 <= len){
                        len = j - i +1;
                        ans = s.substr(i, j-i+1);
                    }
                    break;
                }
                j++;
                if(j >= s.size())
                    break;
                while(hash.find(s[j]) == hash.end() && j != s.size()-1)
                    j++;
                hash[s[j]]--;
            }

            if(j >= s.size())
                break;
            
            hash[s[i]]++;
            i++;
            if(i >= s.size())
                break;
            while(hash.find(s[i]) == hash.end() && i != s.size()-1)
                i++;
            
        }
        return ans;
    }
    bool iscorrect(map<char, int>& hash){
        for(auto it : hash){
            if(it.second > 0)
                return false;
        }
        return true;
    }
};
