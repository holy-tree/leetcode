class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> v;

        bool isself;
        int i;
        for(i = left; i <= right; i++){
            isself = true;
            int num = i;
            while(num > 0){
                if(num % 10 == 0){
                    isself = false;
                    break;
                }
                if(i % (num%10) != 0){
                    isself = false;
                    break;
                }
                num = num / 10;
            }

            if(isself){
                v.push_back(i);
            }
        }

        return v;

    }
};
