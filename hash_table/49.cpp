class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;

        map<string, vector<string>> hash;

        map<string, vector<string>>:: iterator it;
        string temp;
        for(string str : strs){
            temp = str;
            sort(temp.begin(), temp.end());
            it = hash.find(temp);
            if(it == hash.end()){
                hash.insert(pair<string, vector<string>> (temp, vector<string>{str}));
            }
            else{
                it->second.push_back(str);
            }
        }

        for(auto it : hash){
            ans.push_back(it.second);
        }
       

        return ans;


    }
};
