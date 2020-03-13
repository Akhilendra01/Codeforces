#include<bits/stdc++.h>
using namespace std;

int tc=1,n,h,l,r,arr[2003],dp[2003][2003];

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    //scanf("%d",&tc);
}

void input()
{
    scanf("%d%d%d%d",&n,&h,&l,&r);
    for(int i=0;i<n;i++)scanf("%d",arr+i);

}

int ans(int idx,int now)
{
    if(idx == n)return 0;
    if(dp[idx][now] != -1)return dp[idx][now];
    int t1 = (now-1 + arr[idx])%h;
    int t2 = (now + arr[idx])%h;
    int a1 = ans(idx+1,t1) + (l <= t1 && t1 <= r);
    int a2 = ans(idx+1,t2) + (l <= t2 && t2 <= r);
    return dp[idx][now] = max(a1,a2);
}

void solve()
{
    cout << ans(0,0) << endl;
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
