class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == goal[0]){
                if(s.substr(i) + s.substr(0, i) == goal)
                    return true;
            }
        }
        return false;
    }
};
