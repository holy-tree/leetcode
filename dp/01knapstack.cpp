#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> value{20, 30, 65, 40, 60};
    vector<int> weight{10, 20, 30, 40, 50};
    vector<double> vm;
    for(int i = 0; i < value.size(); i++)
        vm.push_back((double)value[i] / weight[i]);

    int dp[11][value.size()+1];
    for(int i = 0; i <= 10; i++)
        for(int j = 0; j <= value.size(); j++)
            dp[i][j] = 0;
    
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= value.size(); j++){
            if(i*10 < weight[j-1])
                dp[i][j] = dp[i][j-1];
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-weight[j-1]/10][j-1] + value[j-1]);
            }
        }
    }

    for(int i = 0; i <= 10; i++){
        for(int j = 0; j <= value.size(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
