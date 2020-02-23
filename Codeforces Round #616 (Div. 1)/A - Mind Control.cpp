#include <bits/stdc++.h>
#define INF 1000000500
using namespace std;

int tc=1,n,m,k,arr[4000];

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}
 
void input()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
 
void solve()
{
    int mx = 0;
    k = min(k,m-1);
    for(int x=0;x<=k;x++)
    {
        int mn = INF;
        for(int y=0;y<m-k;y++)
            mn = min(mn,max(arr[x+y],arr[x+y+n-m]));
        mx = max(mx,mn);
    }
    printf("%d\n",mx);
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
