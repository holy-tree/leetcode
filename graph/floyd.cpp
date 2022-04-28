#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 5;
    int m = 8;
    int dist[5][5];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = 100;

    for(int i = 0; i <= n; i++)
        dist[i][i] = 0;

    dist[0][1] = -1;
    dist[0][2] = 3;
    dist[1][2] = 3;
    dist[1][3] = 2;
    dist[1][4] = 2;
    dist[3][1] = 1;
    dist[3][2] = 5;
    dist[4][3] = -3;


    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%5d ", dist[i][j]);
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}
