class Solution {
public:
    int strongPasswordChecker(string password) {

        int n = password.length();
        
        bool one = true;
        bool misLowChar = 1;
        bool misUpperChar = 1;
        bool misDigit = 1;

        int timesOfRepeat = 0;

        int len = n;

        vector<int> flag(n);

        for(int i = 0; i < n; i++){
            if(misLowChar){
                if(password[i] >= 'a' && password[i] <= 'z')
                    misLowChar = 0;
            }
            if(misUpperChar){
                if(password[i] >= 'A' && password[i] <= 'Z')
                    misUpperChar = 0;
            }
            if(misDigit){
                if(password[i] >= '0' && password[i] <= '9')
                    misDigit = 0;
            }

            if(i > 0 && i < n-1){
                if(password[i] == password[i-1] && password[i] == password[i+1] && (flag[i-1]||flag[i]||flag[i+1]==0)){
                    timesOfRepeat++;
                    flag[i+1] = 1;
                }
                    
            }
        }

        int steps = misDigit + misLowChar + misUpperChar;
        timesOfRepeat = timesOfRepeat > steps ? (timesOfRepeat - steps) : 0;

        steps = steps + timesOfRepeat;

        len = len + steps;

        if(len < 6)
            steps = steps + (6 - len);
        if(len > 20)
            steps = steps + (20 - len);

        return steps;
    }
};
