#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
 
int tc=1,n,a[SIZE],b;
bitset<SIZE> inBackpack;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
}
 
void solve()
{   
    int idx = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b);
        int cnt = 0;
        if(!inBackpack.test(b))
        {
            for(;a[idx]!=b;idx++,cnt++)
                inBackpack.set(a[idx]);
            inBackpack.set(a[idx++]);
            cnt++;
        }
        printf("%d ",cnt);
    }
    printf("\n");
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
