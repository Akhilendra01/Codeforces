#include <bits/stdc++.h>
using namespace std;

int t;
string s;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
}
 
void input()
{
    cin >> s;
}
 
void solve()
{
  int curr=-1,cnt=0;
  for(int i=0;i<s.length();i++)
  {
      if(s[i] == '0')
      {
          if(curr > -1)
            curr++;
      }else{
          if(curr > -1)
            cnt += curr;
          curr = 0;
      }
  }
  cout << cnt << endl;
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
