#include <bits/stdc++.h>
using namespace std;
 
int t,n,m,monsters_powers[200005],best[200005],endurances[200005],hero_power,days,pos,npos;
 
int main(){
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&monsters_powers[i]);
            best[i] = 0;
        }
        best[n] = 0;
        
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&hero_power,&endurances[i]);
            best[endurances[i]] = max(best[endurances[i]],hero_power);
        }
        
        for(int i=n-1;i>=0;i--)best[i] = max(best[i],best[i+1]);
        
        for(days = pos = npos = 0;pos<n;pos=npos,days++)
        {
            for(int mx=0;1;npos++)
            {
                mx = max(mx,monsters_powers[npos]);
                if(mx > best[npos - pos + 1])break;
            }
            if(pos == npos){
                days = -1;
                break;
            }
        }
        
        printf("%d\n",days);
    }
    return 0;
}
