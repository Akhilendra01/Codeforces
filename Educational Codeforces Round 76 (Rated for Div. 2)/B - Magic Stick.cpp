#include<bits/stdc++.h>
using namespace std;
 
int t,a,b;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a == 1)printf("%s\n",b==1?"YES":"NO");
        else if(a < 4)printf("%s\n",b<4?"YES":"NO");
        else printf("YES\n");
    }
    return 0;   
}
