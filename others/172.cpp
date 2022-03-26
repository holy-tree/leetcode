class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        
        int m = 5;
        while(m <= n){
            int mm = m;
            while(mm % 5 == 0){
                count++;
                mm = mm / 5;
            }
            m = m + 5;
        }


        return count;
    }
};
