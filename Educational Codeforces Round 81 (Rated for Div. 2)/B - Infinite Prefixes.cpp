#include <bits/stdc++.h>
#define SIZE 100005
using namespace std;
 
int tc=1,n,x,zeros[SIZE],ones[SIZE];
string str;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;
}
 
void input()
{
    cin >> n >> x >> str;
}
 
void solve()
{
    zeros[0] = ones[0] = 0;
    for(int i=1;i<=n;i++)
    {
        zeros[i] = zeros[i-1];
        ones[i] = ones[i-1];
        if(str[i-1] == '0')zeros[i]++;
        else ones[i]++;
    }
    
    int cnt = 0;
    const int balN = zeros[n] - ones[n];
    for(int i=0;i<n;i++)
    {
        int balI = zeros[i] - ones[i];
        if(!balN)
        {
            if(balI == x){
                cout << -1 << endl;
                return;
            }
        }
        else if(abs(x - balI) % abs(balN) == 0)
        {
            if((x-balI) / balN >= 0)
                cnt++;
        }
    }
    cout << cnt << endl;
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
