class Solution {
public:
    string minimizeResult(string expression) {
        int n = expression.length();
        int index;
        for(index = 0; index < n; index++){
            if(expression[index] == '+')
                break;
        }
       
        int ans = 2147483647;
        int x;
        int y;
        
        for(int i = index-1; i >= 0; i--){
            for(int j = index+1; j < n; j++){
                int num1 = atoi(expression.substr(i, index-i).c_str());
                int num2 = atoi(expression.substr(index+1, j-index).c_str());
                int num3 = atoi(expression.substr(0, i).c_str());
                int num4 = atoi(expression.substr(j+1, n-j).c_str());
                num3 = num3 == 0 ? 1 : num3;
                num4 = num4 == 0 ? 1 : num4;
                
                if((num1+num2)*num3*num4 < ans){
                    x = i;
                    y = j;
                    ans = (num1+num2)*num3*num4;
                }
            }
        }
        expression.insert(y+1, ")");
        expression.insert(x, "(");
        return expression;
        
    }
};
