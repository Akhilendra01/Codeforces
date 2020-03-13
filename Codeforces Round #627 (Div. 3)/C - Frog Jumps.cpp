#include<bits/stdc++.h>
using namespace std;

int tc=1;
string str;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&tc);
    cin >> tc;
}

void input()
{
    cin >> str;
}

void solve()
{
    int len = 1,mx=1;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == 'R')len = 1;
        else len++;
        mx = max(len,mx);
    }
    cout << mx << endl;
}

int main()
{
    preprocess();
    while(tc--)
    {
        input();
        solve();
    }
    return 0;
}
