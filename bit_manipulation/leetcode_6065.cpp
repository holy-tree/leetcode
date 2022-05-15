class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        map<int, int> m;
        
        
        for(int i = 0; i < candidates.size(); i++){
            int jie = 1;
            int temp = candidates[i];
            while(temp > 0){
                if(temp % 2 == 1){
                    if(m.find(jie) == m.end())
                        m.insert(pair<int, int>(jie, 1));
                    else
                        m[jie]++;
                }
                jie++;
                temp = temp / 2;
            }
        }
        int ans = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            cout<<it->first<<" "<<it->second<<endl;
            ans = max(ans, it->second);
        }
        
        return ans;
    }
};
