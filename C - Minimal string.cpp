#include <bits/stdc++.h>
using namespace std;
 
int tc=1;
vector<vector<int>> indices(30);
string s;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> s;
    for(int i=0;i<s.length();i++)
        indices[s[i]-'a'].push_back(i);
}
 
void solve()
{   
    string ans;
    stack<char> t;
    int curr = 0;
    for(char i=0;i<26;i++)
    {
        while(!t.empty() && t.top() <= ('a' + i)){
            ans += t.top();
            t.pop();
        }
        auto it = lower_bound(indices[i].begin(),indices[i].end(),curr);
        for(;it!=indices[i].end();it++)
        {
            for(int j=curr;j<*it;j++)
                t.push(s[j]);
            curr = (*it) + 1;
            ans += ('a' + i);
        }
    }
    while(!t.empty()){
        ans += t.top();
        t.pop();
    }
    cout << ans << endl;
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
C - Minimal string
