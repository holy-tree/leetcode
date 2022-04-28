#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct knapsack
{
    int value;
    int weight;
    double vm;
    knapsack(int value, int weight) : value(value), weight(weight){
        vm = (double)value / weight;
    }
};
bool cmp(knapsack k1, knapsack k2){
    return k1.vm > k2.vm;
}
int main()
{
    vector<knapsack> knapsacks{knapsack(20, 10), knapsack(30, 20), knapsack(65, 30), knapsack(40, 40), knapsack(60, 50)};
    sort(knapsacks.begin(), knapsacks.end(), cmp);

    for(knapsack k : knapsacks){
        cout<<k.value<<" "<<k.weight<<endl;
    }

    int weight = 100;
    int value = 0;
    for(knapsack k : knapsacks){
        int temp = min(weight, k.weight);
        weight = weight - temp;
        value = value + k.vm * temp;
        if(weight == 0)
            break;
    }

    cout<<value<<endl;

    system("pause");

    return 0;
}
