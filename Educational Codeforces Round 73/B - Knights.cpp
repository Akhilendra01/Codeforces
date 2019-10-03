#include <bits/stdc++.h> 
 
using namespace std;
 
int n;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//---------------------------
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i%2)
				cout << (j%2?'W':'B');
			else
				cout << (j%2?'B':'W');
		}
		cout << endl;
	}
	return 0;
}
