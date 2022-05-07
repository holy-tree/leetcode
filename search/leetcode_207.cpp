class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> m;
        for(int i = 0; i < prerequisites.size(); i++){
            if(m.find(prerequisites[i][0]) == m.end())
                m.insert(pair<int, vector<int>>(prerequisites[i][0], vector<int>{prerequisites[i][1]}));
            else
                m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(m.find(i) == m.end())
                q.push(i);
        }
        while(!q.empty()){
            int key = q.front();
            q.pop();
            for(auto it = m.begin(); it != m.end(); it++){
                if(find(it->second.begin(), it->second.end(), key) != it->second.end()){
                    it->second.erase(find(it->second.begin(), it->second.end(), key));
                    if(it->second.empty())
                        q.push(it->first);
                }
            }
        }
        for(auto it = m.begin(); it != m.end(); it++){
            if(!it->second.empty())
                return false;
        }
        return true;
        
    }
};
