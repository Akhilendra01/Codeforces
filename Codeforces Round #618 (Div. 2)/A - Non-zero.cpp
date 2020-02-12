#include <bits/stdc++.h>
using namespace std;

int tc=1,n,sum,cnt;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}

void input()
{
    sum=cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int in;
        scanf("%d",&in);
        sum += in;
        if(!in)cnt++;
    }
}

void solve()
{   
    printf("%d\n",sum+cnt?cnt:cnt+1);
}

int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
