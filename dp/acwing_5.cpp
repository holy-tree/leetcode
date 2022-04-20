#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, v;
    cin>>n>>v;

    vector<int> volumn;
    vector<int> value;

    int vo, va, num, k;
    for(int i = 0; i < n; i++){
        cin>>vo>>va>>num;
        k = 1;
        while(num >= k){
            volumn.push_back(vo * k);
            value.push_back(va * k);
            num -= k;
            k *= 2;
        }
        if(num > 0){
            volumn.push_back(vo * num);
            value.push_back(va * num);
        }
    }


    // int dp[v+1][volumn.size()+1];

    // for(int i = 0; i <= v; i++)
    //     for(int j = 0; j <= volumn.size(); j++)
    //         dp[i][j] = 0;

    // for(int i = 1; i <= v; i++){
    //     for(int j = 1; j <= volumn.size(); j++){
    //         if(i < volumn[j-1])
    //             dp[i][j] = dp[i][j-1];
    //         else
    //             dp[i][j] = max(dp[i][j-1], dp[i-volumn[j-1]][j-1] + value[j-1]);
    //     }
    // }

    int f[v+1];
    for(int i = 0; i <= v; i++)
        f[i] = 0;


    for(int i = 0; i < volumn.size(); i++)
        for(int j = v; j >= volumn[i]; j--){
            f[j] = max(f[j], f[j - volumn[i]] + value[i]);
        }

    cout<<f[v];

    // for(int i = 1; i <= v; i++){
    //     for(int j = 1; j <= volumn.size(); j++){
    //         cout<<dp[i][j]<<" ";    
    //     }
    //     cout<<endl;
    // }


    // cout<<dp[v][volumn.size()];

    system("pause");
    return 0;
}
