#include <bits/stdc++.h> 
 
using namespace std;
 
int q,n,m,x;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//---------------------------
	cin >> q;
	while(q--)
	{
		cin >> n >> m >> x;
		cout << min(min(n,m),(n+m+x)/3) << endl;
	}
	
	return 0;
}
