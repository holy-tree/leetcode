#include<bits/stdc++.h>

using namespace std;

struct knapsack
{
    int weight;
    int value;
    knapsack(int value, int weight) : weight(weight), value(value){}
};

int weight = 100;
int value = 0;   
map<int, vector<int>> m;
void backtrace(vector<knapsack>& kanpsacks, int k, int w, int v);
int main()
{
    vector<knapsack> knapsacks{knapsack(20, 10), knapsack(30, 20), knapsack(65, 30), knapsack(40, 40), knapsack(60, 50)};

    backtrace(knapsacks, 0, 0, 0);

    cout<<value<<endl;

    for(auto it = m.begin(); it != m.end(); it++){
        for(int i : it->second)
            printf("%5d", i);
        cout<<endl;
    }

    system("pause");
    return 0;
}
void backtrace(vector<knapsack>& kanpsacks, int k, int w, int v){

    if(m.find(k) == m.end())
        m.insert(pair<int, vector<int>>(k, vector<int>{v}));
    else
        m.find(k)->second.push_back(v);

    if(kanpsacks[k].weight + w > weight){
        value = max(value, v);
        return;    
    }

    int ww = w;
    int vv = v;
    for(int i = k; i < kanpsacks.size(); i++){
        ww += kanpsacks[i].weight;
        vv += kanpsacks[i].value;   
    }
    if(ww <= weight){
        value = max(value, vv);
        return;
    }

    if(k == kanpsacks.size()-1)
        return;
    
    backtrace(kanpsacks, k+1, w+kanpsacks[k].weight, v+kanpsacks[k].value);
    backtrace(kanpsacks, k+1, w, v);
}   
