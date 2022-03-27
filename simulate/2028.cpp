class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        vector<int> result;

        if(mean <= 0 || mean > 6)
            return result;

        int sum = 0;
        for(int i : rolls){
            sum = sum + i;
        }

        int s = mean * (rolls.size() + n) - sum;
        if(s < n || s > n*6){
            return result;
        }


        while(n >= 1){
            int a = s / n;
            result.push_back(a);
            s = s - a;
            n--;
        }

        return result;

    }
};
