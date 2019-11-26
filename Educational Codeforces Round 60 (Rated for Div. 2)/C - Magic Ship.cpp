#include<bits/stdc++.h>
#define ll long long int
#define N 100005
using namespace std;
 
ll sx,sy,ex,ey,n;
string s;
map<char,pair<ll,ll>> dir = {{'U',{0,1}},{'D',{0,-1}},{'L',{-1,0}},{'R',{1,0}}};
pair<ll,ll> wind;
ll xd[N],yd[N];
 
bool can(ll mid)
{
    ll cnt = mid/n,rem = mid%n;
    ll x = sx + cnt * xd[n] + xd[rem];
    ll y = sy + cnt * yd[n] + yd[rem];
    ll distance = abs(ex-x) + abs(ey-y);
    return distance <= mid;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> sx >> sy >> ex >> ey >> n >> s;
    for(int i=1;i<=n;i++)
    {
        wind = dir[s[i-1]];
        xd[i] = xd[i-1]+wind.first;
        yd[i] = yd[i-1]+wind.second;
    }
    ll l=0,r=1e18;
    while(l+1 < r)
    {
        ll mid = l + (r-l)/2;
        if(can(mid))r=mid;
        else l = mid;
    }
    if(r > 2e14)return cout << -1 << endl,0;
    cout << r << endl;
    return 0;   
}
