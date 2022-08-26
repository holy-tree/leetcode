class Solution {
typedef struct e{
    int num;
    int count;
    e(int n){
        num = n;
        count = 1;
    }
}elem;

bool static cmp(elem a, elem b){
    return a.count > b.count;
}

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<elem> v;
        vector<int> ans;
        map<int ,int> location;
        int loca = 0;

        for(int i : nums){
            if(location.find(i) == location.end()){
                v.push_back(e(i));
                location.insert(pair(i, loca));
                loca++;
            }
            else{
                v[location[i]].count++;
            }
        }
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].num);
        }


        return ans;
    }
};
