class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd;
        vector<int> even;
        
        int n = num;
        
        while(n > 0){
            if((n % 10) % 2 == 0)
                even.push_back(n%10);
            else
                odd.push_back(n%10);
            n = n / 10;
        }
        
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        long long ans = 0;
        int i = 0;
        int j = 0;
        long long time = 1;
        while(num > 0){
            if((num % 10) % 2 == 0){
                ans = ans + time*even[j];
                j++;
                time = time * 10;
            }
            else{
                ans = ans + time * odd[i];
                i++;
                time = time * 10;
            }
            num = num / 10;
        }
        
        return ans;
        
    }
};
