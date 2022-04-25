class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minnum = prices[0];
        int maxnum = prices[0];

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minnum){
                minnum = prices[i];
                maxnum = prices[i];
            }
            if(prices[i] > maxnum){
                maxnum = prices[i];
                ans = max(ans, maxnum-minnum);
            }
        }
        return ans;
    }
};
