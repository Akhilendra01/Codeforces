#include<bits/stdc++.h>
using namespace std;
 
int q;
string s;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //------------------------------
    cin >> q;
    while(q--)
    {
        vector<char> odds;
        vector<char> evens;
        cin >> s;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]-'0') % 2)odds.push_back(s[i]);
            else evens.push_back(s[i]);
        }
        string res = "";
        int i=0,j=0;
        while(i<odds.size()&&j<evens.size())
        {
            if(odds[i] < evens[j])
            {
                res += odds[i];
                i++;
            }else{
                res += evens[j];
                j++;
            }
        }
        while(i<odds.size())
        {
            res += odds[i];
            i++;   
        }
        while(j<evens.size())
        {
            res += evens[j];
            j++;   
        }
        cout << res << endl;
    }
    return 0;
}
