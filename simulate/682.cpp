class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score = 0;
        vector<int> num;
        for(string s : ops){
            if( (s[0] >= '0' && s[0] <= '9') || s[0] == '-'){
                num.push_back(atoi(s.c_str()));
            }
            else if(s == "C"){
                num.erase(num.end()-1);
            }
            else if(s == "D"){
                num.push_back(2*num[num.size()-1]);
            }
            else if(s == "+"){
                num.push_back(num[num.size()-1] + num[num.size()-2]);
            }
        }

        for(int s : num){
            score = score + s;
        }
        return score;
    }
};
