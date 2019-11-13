#include <bits/stdc++.h>
using namespace std;
 
int t,n,x,a,b,diff;
 
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
        scanf("%d%d%d%d",&n,&x,&a,&b);
        if(a>b)swap(a,b);
        diff = min(x,a-1);
        a -= diff;
        x -= diff;
        b += min(x,n-b);
        printf("%d\n",b-a);
    }
    return 0;
}
