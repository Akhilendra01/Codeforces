
#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;
 
int n,s[2000006],cf[11][11] = {0};
char str[2000006];
 
int main(){
    scanf("%s",str);
    n = strlen(str);
    for(int i=0;i<n;i++)s[i]= str[i] - '0';
    
    for(int i=1;i<n;i++)cf[s[i-1]][s[i]]++;
    
    for(int x=0;x<10;x++)
    {
        for(int y=0;y<10;y++)
        {
            int ds[11][11];
            for(int i=0;i<10;i++)for(int j=0;j<10;j++)ds[i][j] = INF + 7;
            for(int v=0;v<10;v++)
            {
                for(int cx=0;cx<10;cx++)
                {
                    for(int cy=0;cy<10;cy++)
                    {
                        if(cx+cy == 0)continue;
                        int to = (v+cx*x+cy*y) % 10;
                        ds[v][to] = min(ds[v][to],cx+cy);
                    }
                }
            }
            
            
            int res = 0;
            for (int v=0;v<10;v++) {
                for (int to=0;to<10;to++) {
                    if (ds[v][to] > INF && cf[v][to] > 0) {
                        res = -1;
                        break;
                    }
                    res += (ds[v][to] - 1) * cf[v][to];
                }
                if (res == -1)
                    break;
            }
 
            printf("%d ",res);
            
        }
        printf("\n");
    }
    return 0;
}
