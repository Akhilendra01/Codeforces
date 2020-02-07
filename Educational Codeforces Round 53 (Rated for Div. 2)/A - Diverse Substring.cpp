#include <bits/stdc++.h>
#define SIZE 1003
using namespace std;
 
int tc=1,n;
string s;
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> n >> s;
}
 
void solve()
{   
    int idx = 0;
    for(int i=1;i<n&&!idx;i++)
        if(s[i] != s[i-1])
            idx = i;
    if(idx)
        cout << "YES" << endl << s[idx-1] << s[idx] << endl;
    else
        cout << "NO" << endl;
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
