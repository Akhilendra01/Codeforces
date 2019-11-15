#include <bits/stdc++.h>
using namespace std;
 
int t,n,in;
int last[200005];
 
int main()
{
    //Presetup:
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //-------------------------------
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(last,-1,(n+5)*sizeof(last[0]));
        int mn = (int)3e5;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&in);
            if(last[in] != -1)mn = min(mn,i-last[in]+1);
            last[in] = i;
        }
        printf("%d\n",mn == (int)3e5?-1:mn);
    }
    return 0;
}
