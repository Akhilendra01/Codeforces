#include <bits/stdc++.h>
#define SIZE 200005
#define ll long long int
using namespace std;

int tc=1,n,a[SIZE];
ll t;
vector<int> mx;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    scanf("%d%lld",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
}

void solve()
{   
    ll sum = 0;
    for(int i=0;i<n;i++){
        mx.push_back(a[i]);
        sum += (ll)a[i];
    }
    sort(mx.begin(),mx.end());
    ll ans = 0;
    int idx = n;
    while(1)
    {
        while(idx!=0 && mx[idx-1] > t)
            sum-=mx[--idx];
        
        if(!idx)break;
        if(sum <= t){
            ans += t/sum * (ll)idx;
            t %= sum;
        }else{
            for(int i=0;i<n;i++)
            if(a[i] <= t)
            {
                ans++;
                t-=a[i];
            }
        }
    }
    
    printf("%lld\n",ans);
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
