class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num : nums)
            pq.push(-num);
        while(k > 0){
            pq.push(pq.top()-1);
            pq.pop();
            k--;
        }
        long ans = 1;
        for(int i = 0; i < nums.size(); i++){
            ans = ans * (-pq.top()) % 1000000007;
            pq.pop();
        }
        return ans;
    }
};
