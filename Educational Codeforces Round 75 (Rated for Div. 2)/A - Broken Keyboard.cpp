#include<bits/stdc++.h>
using namespace std;
 
int t;
string s,res;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //------------------------------
    cin >> t;
    while(t--)
    {
        cin >> s;
        bool flag[30] = {0};
        int cnt = 1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i] == s[i-1])
                cnt++;
            else
            {
                if(cnt%2)flag[s[i-1]-'a']=1;
                cnt = 1;
            }
        }
        if(cnt%2)flag[s[s.length()-1]-'a']=1;
        res = "";
        for(char c='a';c<='z';c++)
            if(flag[c-'a'])res += c;
        cout << res << endl;
    }
    return 0;
}
