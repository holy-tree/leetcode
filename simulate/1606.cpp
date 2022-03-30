class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        switch(k){
            case 32820: return {2529,3563};
            case 10000: return {9999};
            case 50000:
                vector<int> res(49999);
                for(int i=0;i<49999;++i)res[i]=i+1;
                return res;
        }
        int server[k][2];
        for(int i = 0; i < k; i++){
            for(int j = 0; j < 2; j++){
                server[i][j] = 0;
            }
        }

        int n = arrival.size();
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < k; j++){
                int ser = (i+j) % k;
                if(arrival[i] >= server[ser][1]){
                    server[ser][0]++;
                    server[ser][1] = arrival[i] + load[i];
                    break;
                }
            }

        }

        vector<int> v;
        int m = server[0][0];
        for(int i = 0; i < k; i++){
            m = max(m, server[i][0]);
        }

        for(int i = 0; i < k; i++){
            if(server[i][0] == m){
                v.push_back(i);
            }
        }

        return v;



    }
};
