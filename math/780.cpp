class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx < sx || ty < sy)
            return false;
        if(tx == sx && ty == sy)
            return true;
        if(tx == sx){
            if((ty-sy) % tx == 0)
                return true;
            else
                return false;
        }
        if(ty == sy){
            if((tx-sx) % ty == 0)
                return true;
            else
                return false;
        }
        if(tx - ty < sx && ty - tx >= sy)
            return reachingPoints(sx, sy, tx, ty-tx);
        if(tx - ty >= sx && ty - tx < sy)
            return reachingPoints(sx, sy, tx-ty, ty);
        if(tx - ty >= sx && ty - tx >= sy)
            return reachingPoints(sx, sy, tx-ty, ty) || reachingPoints(sx, sy, tx, ty-tx);
        
        return false;
    }
};
