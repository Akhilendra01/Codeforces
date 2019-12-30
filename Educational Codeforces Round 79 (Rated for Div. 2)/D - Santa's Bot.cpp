
#include <bits/stdc++.h>
#define mod 998244353
#define SIZE 1000006
using namespace std;
 
int n,k,x,y,inv[SIZE];
vector<vector<int>> items;
map<int,int> cnt;
 
 
int mul(int a, int b) {
	return a * 1ll * b % mod;
}
 
int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
 
void preprocess()
{
    for(int i=0;i<SIZE;i++)inv[i] = binpow(i, mod-2);
}
 
void input()
{
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    items.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        items[i].resize(k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&items[i][j]);
            cnt[items[i][j]]++;
        }
    }
}
 
void solve()
{
    int ans = 0;
    for(vector<int> arr:items)
    {
        for(int item:arr){
            ans = (ans + mul(mul(inv[arr.size()],inv[n]),mul(cnt[item],inv[n])) ) % mod;
        }
    }
    
    printf("%d\n",ans);
}
 
int main()
{
    preprocess();
    input();
    solve();
    return 0;
}
