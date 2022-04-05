class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        int temp;
        int count;
        for(int i = left; i <= right; i++){
            temp = i;
            count = 0;
            while(temp != 0){
                if(temp % 2 == 1){
                    count++;
                }
                temp = temp / 2;
            }
            
            if(isPrime(count))
                ans++;
            
        }
        return ans;

    }
    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    



};
