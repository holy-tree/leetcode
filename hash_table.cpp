class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        // sort(arr.begin(), arr.end());

        // while(arr.size() > 1){
        //     vector<int>::iterator it;
        //     if(arr[0] >= 0)
        //         it = find(arr.begin()+1, arr.end(), (double)arr[0] * 2);
        //     else
        //         it = find(arr.begin()+1, arr.end(), (double)arr[0]/2);


        //     if(it == arr.end()){
            
        //         return false;
        //     }

        //     arr.erase(it);
        //     arr.erase(arr.begin());
            
        // }

        // return true;


        map<double, double> m;
        for (auto& num : A) {
            m[num]++;
        }
        for (auto& [c, d] : m) {
            if (d < 0) return false;
            if (d == 0) continue;
            if (c > 0) {
                if (!m.count(c * 2)) return false;
                m[c * 2] -= d;
            } else {
                if (!m.count(c / 2.0)) return false;
                m[c / 2.0] -= d;
            }
        }
        return true;

    }
};
