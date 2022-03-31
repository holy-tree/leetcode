class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        int ans = 0;

        int l = 0;
        int r = n-1;

        int lm = height[l];
        int rm = height[r];
        int h = min(lm, rm);

        while(l < r){
            if(height[l] > lm)
                lm = height[l];
            if(height[r] > rm)
                rm = height[r];

            h = min(lm, rm);

            if(height[l] >= height[r]){
                ans = ans + h - height[r];
                r--;
            }
            else if(height[l] < height[r]){
                ans = ans + h - height[l];
                l++;
            }
        }

    

        return ans;


    }
};
