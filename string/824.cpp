class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans;
        int i = 0;
        int j = 0;
        string str;
        int count = 1;
        while(j < sentence.size()){
            while(sentence[j] != ' ' && j < sentence.size())   
                j++;
            str = sentence.substr(i, j-i);
            if(str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'A' || str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U' ){
                ans = ans + str + "ma";
            }
            else{
                ans = ans + str.substr(1) + str[0] + "ma";
            }
            for(int i = 0; i < count; i++)
                ans = ans + 'a';
            count++;
            if(j < sentence.size())
                ans = ans + ' ';
            j++;
            i = j;
        }

        return ans;
    }
};
