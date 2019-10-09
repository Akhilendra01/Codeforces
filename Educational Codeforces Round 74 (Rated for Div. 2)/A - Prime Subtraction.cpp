#include <bits/stdc++.h>
 
using namespace std;
 
int t;
long long int n,r;
 
int main() {
    cin >> t;
    while(t--)
    {
        cin >> n >> r;
        if(n-r > 1)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
} 
