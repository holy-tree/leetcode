#include<iostream>
#include<cstdio>
using namespace std;

int main( )
{
    float c[1010]={0};
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int n;
        float m;
        scanf("%d%f",&n,&m);
        c[n]+=m;
    }
    
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int n;
        float m;
        scanf("%d%f",&n,&m);
        c[n]+=m;
    }
    
    int cnt=0;
    for(int i=0;i<1010;i++)
    {
        if(c[i]!=0) cnt++;
    }
    printf("%d",cnt);
    for(int i=1009;i>=0;i--)
    {
        if(c[i]!=0)
            printf(" %d %.1f",i,c[i]);
    }
        return 0;
}
