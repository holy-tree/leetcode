#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> jobs = {15,8,3,10};
    sort(jobs.begin(), jobs.end());

    int sum = 0;
    int s = 0;
    for(int job : jobs){
        s = s + job;
        sum = sum + s;
    }
    cout<<sum/jobs.size()<<endl;


    system("pause");
    return 0;
}
