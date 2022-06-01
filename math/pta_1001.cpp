#include<bits/stdc++.h>

using namespace std;
int main()
{
    int a, b;
    cin>>a>>b;
    int c = a + b;
    string s = to_string(c);
    int count = 0;
    for(int i = s.length()-1; i >= 0; i--){
        if(count % 3 == 0){
            if(s[i] != '-' && i != s.length()-1){
                s.insert(i+1, ",");
            }
        }
        count++;
    }
    cout<<s<<endl;
    return 0;
}
