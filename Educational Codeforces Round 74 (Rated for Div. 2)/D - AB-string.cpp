#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll n;
string s;
 
int main()
{
    cin >> n >> s;
    ll total = n*(n+1)/2;
    ll bad = 0;
    ll cnt = 1;
    for(int i=1;i<n;i++)
    {
        if(s[i] == s[i-1])cnt++;
        else{
            bad += cnt;
            cnt = 1;
        }
    }
    cnt = 1;
    for(int i=n-2;i>=0;i--)
    {
        if(s[i] == s[i+1])cnt++;
        else{
            cnt--;
            bad += cnt;
            cnt = 1;
        }
    }
    cout << (total-bad-n) << endl;
    return 0;
}
