#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n = 5;
    int m = 8;

    int dist[5];
    for(int i = 0; i < 5; i++)
        dist[i] = 1e9;
    
    vector<int> vt[8];
    vt[0] = {0, 1, -1};
    vt[1] = {0, 2, 3};
    vt[2] = {1, 2, 3};
    vt[3] = {1, 3, 2};
    vt[4] = {1, 4, 2};
    vt[5] = {3, 1, 1};
    vt[6] = {3, 2, 5};
    vt[7] = {4, 3, -3};

    dist[0] = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[vt[j][0]] + vt[j][2] < dist[vt[j][1]])
                dist[vt[j][1]] = dist[vt[j][0]] + vt[j][2];
        }
    }

    for(int i = 0; i < 5; i++)
        cout<<dist[i]<<endl;

    system("pause");
    return 0;
}
