#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int tc=1;
ll n;
 
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%lld",&n);
}
 
void solve()
{   
    printf("%lld\n",4*3*(2*binpow(4,n-3)+(3*n-9)*binpow(4,n-4)));
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
