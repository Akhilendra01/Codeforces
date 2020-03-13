#include<bits/stdc++.h>
#define SIZE 200005
#define ll long long int
using namespace std;
 
int tc=1,n;
vector<ll> diffs;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&tc);
    //cin >> tc;
}
 
void input()
{
    scanf("%d",&n);
    diffs.resize(n);
    for(int i=0;i<n;i++)scanf("%lld",&diffs[i]);
    for(int i=0;i<n;i++)
    {
        ll in;
        scanf("%lld",&in);
        diffs[i] -= in;
    }
}
 
void solve()
{
    sort(diffs.begin(),diffs.end());
    auto iter =  lower_bound(diffs.begin(),diffs.end(),1);
    ll res = 0;
    for(int i=iter-diffs.begin();i<n;i++)
    {
        iter =  lower_bound(diffs.begin(),diffs.begin()+i,1 - diffs[i]);
        res += diffs.begin()+i - iter;
    }
    printf("%lld\n",res);
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
