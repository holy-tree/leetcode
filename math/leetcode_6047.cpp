class Solution {
public:
    string removeDigit(string number, char digit) {
        int index = 0;
        string ans = "0";
        while(index < number.length()){
            if(number[index] == digit){
                string temp = number;
                temp.erase(temp.begin()+index);
                ans = max(ans, temp);
            }
            index++;
        }
        return ans;
    }
};
