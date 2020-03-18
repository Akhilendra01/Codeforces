#include<bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vector<string> t(m);
    for(int i=0;i<n;i++)cin >> s[i];
    for(int i=0;i<m;i++)cin >> t[i];
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int year;
        cin >> year;
        year--;
        cout << s[year%n] << t[year%m] << endl;
    }
    return 0; 
}
