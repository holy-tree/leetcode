class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> ans;
        
        for(vector<int>& circle : circles){
            int point1 = circle[0] - circle[2];
            int point2 = circle[1] - circle[2];
            int point3 = circle[0] + circle[2];
            int point4 = circle[1] + circle[2];
            
           
            
            for(int i = point1; i <= point3; i++){
                for(int j = point2; j <= point4; j++){
                    
                    if( (i-circle[0])*(i-circle[0]) + (j-circle[1])*(j-circle[1]) <= circle[2]*circle[2] ){
                        ans.insert(pair<int, int>(i, j));
                    }
                }
            }
        }
        for(pair<int, int> p : ans){
            cout<<p.first<<" "<<p.second<<endl;
        }
      
        
        return ans.size();
        
    }
};
