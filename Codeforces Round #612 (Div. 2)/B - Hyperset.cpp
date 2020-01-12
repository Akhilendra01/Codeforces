
#include <bits/stdc++.h>
using namespace std;
 
int t=1,n,k;
string str[2000];
set<string> dict;
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> str[i];
        dict.insert(str[i]);
    }
}
 
void solve()
{
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string third = "";
            for(int c=0;c<k;c++){
                if(str[i][c] == str[j][c])third+=str[i][c];
                else third += (char)('S'+'E'+'T' - str[i][c] - str[j][c]);
            }
            cnt+=dict.find(third)!=dict.end();
        }
    }
    printf("%d\n",cnt/3);
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
