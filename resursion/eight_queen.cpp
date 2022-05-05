#include<bits/stdc++.h>

using namespace std;

int queen[8][8] = {0};
int num = 0;
bool check(int i, int j);
void find_queen(int i);
int main()
{
    find_queen(0);

    cout<<num<<endl;

    

    system("pause");
    return 0;
}
void find_queen(int i){
    if(i > 7){
        num++;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++)
                cout<<queen[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return;

    }

    for(int j = 0; j < 8; j++){
        if(check(i, j)){
            queen[i][j] = 1;
            find_queen(i+1);
            queen[i][j] = 0;
        }
    }

}
bool check(int i, int j){
    for(int k = 0; k < 8; k++){
        if(queen[i][k] == 1)
            return false;
        if(queen[k][j] == 1)
            return false;
    }
    for(int k = 1; i-k>=0 && j-k>=0; k++)
        if(queen[i-k][j-k] == 1)
            return false;
    for(int k = 1; i+k<8 && j+k<8; k++)
        if(queen[i+k][j+k] == 1)
            return false;
    for(int k = 1; i-k>=0 && j+k<8; k++)
        if(queen[i-k][j+k] == 1)
            return false;
    for(int k = 1; i+k<8 && j-k>=0; k++)
        if(queen[i+k][j-k] == 1)
            return false;
    return true;
}
