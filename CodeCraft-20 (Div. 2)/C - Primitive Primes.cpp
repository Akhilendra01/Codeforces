#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll tc=1,n,m,p,in,x=-1,y=-1;


void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&tc);
}

void input()
{
    scanf("%lld%lld%lld",&n,&m,&p);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&in);
        if(in%p != 0 && x==-1)x = i; 
    }

    for(int i=0;i<m;i++)
    {
        scanf("%lld",&in);
        if(in%p != 0 && y==-1)y = i; 
    }
}

void solve()
{
    printf("%lld\n",x+y);
}

int main()
{
    preprocess();
    while(tc--)
    {
        input();
        solve();
    }
    return 0;
}
