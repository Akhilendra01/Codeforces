#include <bits/stdc++.h>
using namespace std;
 
int tc=1,n,w[3];
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}
 
void input()
{
    scanf("%d%d%d%d",w,w+1,w+2,&n);
}
 
int solve()
{
    if((w[0]+w[1]+w[2]+n)%3)return printf("NO\n");
    sort(w,w+3);
    n -= 2*w[2] - w[1] - w[0];
    puts((n>=0 && n%3 == 0)?"YES":"NO");
}
 
int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
