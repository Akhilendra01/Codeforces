#include <bits/stdc++.h>
using namespace std;
 
int t,n,i;
char str[102];
int main(){
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&n,str);
        for(i=0;i<n && str[i]!='8';i++);
        printf("%s\n",n-i>=11?"YES":"NO");
    }
    return 0;
}
