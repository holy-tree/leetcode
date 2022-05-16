class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++)
            pq.push(pair<int, int>(nums[i], i));
        
        vector<int> ans{pq.top().first};
        for(int i = 1; i <= nums.size()-k; i++){
            pq.push(pair<int, int>(nums[i+k-1], i+k-1));
            while(pq.top().second < i)
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
