#include <bits/stdc++.h> 
#define ll long long int
#define SIZE (int)(3e5) + 5
using namespace std;
 
int h[SIZE];
int cost[SIZE];
ll dp[SIZE][3];
 
int q,n;
 
ll ans(int pos,int add)
{
	ll& res = dp[pos][add];
	if(res!=-1)return res;
 
	if(pos == n)return 0;
	res = INT64_MAX;
	for(int x=0;x<3;x++)
		if(h[pos]+x != h[pos-1]+add)
			res = min(res, ans(pos+1,x) + x*cost[pos] );
	return res;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//---------------------------
	cin >> q;
	while(q--)
	{
		cin >> n;
		vector<pair<int,int>> col(n+1);
		for(int i=0;i<n;i++)
		{
			cin >> h[i] >> cost[i];
			dp[i][0] = dp[i][1] = dp[i][2] = -1;
		}
			dp[n][0] = dp[n][1] = dp[n][2] = -1;
		cout << min( min( ans(1,0) , ans(1,1) + cost[0] ), ans(1,2) + 2*cost[0] ) << endl;
	}
	
	return 0;
}
