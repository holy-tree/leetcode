class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        vector<vector<int>> vvt;
        for(vector<int> vt : grid){
            int temp = 0;
            for(int i = 0; i < vt.size(); i++){
                if(vt[i] != 0)
                    num1++;
                temp = max(temp, vt[i]);
                if(vvt.size() < i+1){
                    vvt.push_back(vector<int>());
                }
                vvt[i].push_back(vt[i]);
            }
            num2 = num2 + temp;
        }

        for(vector<int> vt : vvt){
            int temp = 0;
            for(int v : vt){
                temp = max(temp, v);
            }
            num3 = num3 + temp;
        }
        return num1+num2+num3;

    }
};
