class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int sum = 0;
        int a = 0;
        int s = min(start, destination);
        int d = max(start, destination);
        for(int i = 0; i < n; i++){
            sum = sum + distance[i];
            if(i >= s && i < d)
                a = a + distance[i];
        }
        return min(a, sum-a);
    }
};
