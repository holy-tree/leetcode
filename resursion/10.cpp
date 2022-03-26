class Solution {
public:
    bool isMatch(string s, string p) {

        return match(s, p, ' ');
    }

    bool match(string s, string p, char f){
        if(s.size() > 0 && p.size() > 0 && s[s.size()-1] != p[p.size()-1] && p[p.size()-1] != '.' && p[p.size()-1] != '*')
            return false;

        if(s.size() == 0 && p.size() == 0){
            return true;
        }
        if(p.size() == 0)
            return false;
        if(s.size() == 0){
            if(p.size() > 0 && p[0] == '*'){
                return match(s, p.substr(1, p.size()-1), ' ');
            }
            if(p.size() > 1 && p[1] == '*')
                return match(s, p.substr(2, p.size()-2), ' ');

            return false;
        }


        if(s[0] != p[0] && p[0] != '.' && p.size() > 1 && p[1] == '*')
            return match(s, p.substr(2, p.size()-2), p[0]);

        if(s[0] == p[0] || p[0] == '.'){
            if(p.size() > 2 && p[1] == '*')
                return match(s.substr(1, s.size()-1), p.substr(1, p.size()-1), p[0]) || match(s, p.substr(2, p.size()-2), ' ');
            return match(s.substr(1, s.size()-1), p.substr(1, p.size()-1), p[0]);
        }

        if(p[0] == '*'){
            string c(1, f);
            return match(s, p.substr(1, p.size()-1), p[0]) || match(s, c+p, p[0]);
        }

        return false;
    }
};
