
#include <bits/stdc++.h>
#define SIZE 250005
using namespace std;
 
int t=1,n,mod,fact[SIZE];
 
int add(int a, int b);
int mul(int a, int b);
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d%d",&n,&mod);
}
 
void solve()
{
    fact[0] = 1;
    for(int i=1;i<=n;i++)fact[i] = mul(fact[i-1],i);
    int res = 0;
    for(int m=1;m<=n;m++)res = add(res, mul( n-m+1 , mul( fact[m] , fact[n-m+1] ) ) );
    printf("%d\n",res);
}
 
int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
 
int add(int a, int b) {
    a += b;
	if (a >= mod) {
		a -= mod;
	}
    return a;
}
 
int mul(int a, int b) {
	return a * 1ll * b % mod;
}
