#include <bits/stdc++.h>
using namespace std;
 
int t=1,n;
string str;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
}
 
void input()
{
    cin >> n >> str;
}
 
void solve()
{
    bool A = false;
    int mx=0,dist;
    for(int i=0;i<n;i++)
    {
        if(str[i] == 'A'){
            A = true;
            dist = 0;
        }else{
            if(A){
                dist++;
                mx = max(dist,mx);
            }
        }
    }
    cout << mx << endl;
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
