class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n == 1)
            return true;
        int a[2];
        int b = 1;
        a[0] = n % 2;
        n = n / 2;
        while(n > 0){
            a[b%2] = n % 2;
            b++;
            n = n / 2;
            if(a[0] == a[1])
                return false;
        }

        return true;
    }
};
