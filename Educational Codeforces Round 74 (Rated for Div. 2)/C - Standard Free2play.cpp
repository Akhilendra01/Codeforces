#include<bits/stdc++.h> 
using namespace std;
 
int t,h,n; 
 
int main()
{
    cin>>t;
    while(t--)
    {
        cin >> h >> n;
        vector<int> up(n+1);
        up[n] = 0;
        for(int i=0;i<n;i++)
            cin >> up[i];
        int ans = 0,i=0;
        while(up[i]>1)
        {
            if(up[i] == up[i+1]+1)
            {
                if(up[i+2]!=up[i]-2)
                {
                    ans++;
                    up[i+1] = up[i]-2;
                    i++;
                }else
                    i += 2;
            }else 
                up[i] = up[i+1] + 1;
        }
        cout << ans << endl;
    }
}
