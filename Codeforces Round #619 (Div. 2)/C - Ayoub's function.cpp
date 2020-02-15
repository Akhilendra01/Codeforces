#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int tc=1,n,m;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}
 
void input()
{
    scanf("%d%d",&n,&m);
}
 
void solve()
{   
 
    ll z = n - m,g=m+1;
    ll k = z / g;
    ll sum = ((ll) k * (k+1) / 2) * g;
    ll rem = (k+1)*(z%g);
    printf("%lld\n",(ll)n*(n+1)/2 - sum - rem);
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
