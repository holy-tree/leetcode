#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vt{-2, 11, -4, 13, -5, -2};

    vector<int> sum(6);
    sum[0] = -2;
    int s = -2;
    for(int i = 1; i < 6; i++){
        sum[i] = max(sum[i-1]+vt[i], vt[i]);
        s = max(s, sum[i]);
    }

    cout<<s<<endl;

    system("pause");
    return 0;
}
