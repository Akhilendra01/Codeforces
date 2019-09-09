#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
 
int n,m,k,ans;
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		cout << max(k+1 - max((int)floor((m+k-n)/2.0)+1,0),0) << endl;
	}
    return 0;
}
