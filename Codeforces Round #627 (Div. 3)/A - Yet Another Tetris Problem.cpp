#include<bits/stdc++.h>
using namespace std;

int tc=1,n,arr[102];

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}

void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
}

void solve()
{
    int cnt = 0;
    for(int i=0;i<n;i++)
        cnt += arr[i] % 2;
    puts((cnt==n||cnt==0)?"YES":"NO");
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
