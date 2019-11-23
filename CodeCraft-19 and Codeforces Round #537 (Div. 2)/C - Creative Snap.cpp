#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll n,k,a,b,in;
vector<ll> avenger;
 
ll cost(ll l,ll r)
{
    ll i = lower_bound(avenger.begin(),avenger.end(),l) - avenger.begin();
    ll j = upper_bound(avenger.begin(),avenger.end(),r) - avenger.begin();
    ll cnt = j-i;
    if(!cnt)return a;
    ll currCost = b * cnt * (r - l + 1);
    if(l!=r){
        ll left = cost(l,(l+r)/2);
        ll right = cost((l+r)/2+1,r);
        currCost = min(currCost , left + right);
    }
    return currCost;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%lld%lld%lld%lld",&n,&k,&a,&b); 
    for(int i=0;i<k;i++){
        scanf("%lld",&in);
        avenger.push_back(in);
    }
    sort(avenger.begin(),avenger.end());
    printf("%lld\n",cost(1,1<<n));
    return 0;   
}
