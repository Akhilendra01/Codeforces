#include<bits/stdc++.h>
#define ll long long int
#define l(i) p[i].first
#define r(i) p[i].second
using namespace std;
 
int t,n;
ll s;
pair<int,int> p[200005];
 
bool valid(int mid)
{
    ll sum = 0;
    int cnt = 0;
    vector<int> g3;
    for(int i=0;i<n;i++)
    {
        if(r(i) < mid)
            sum += l(i);
        else if(mid < l(i))
        {
            cnt++;
            sum += l(i);
        }else
            g3.push_back(l(i));
    }
    int needed = max(0,(n+1)/2 - cnt);
    if(g3.size()  < needed)return false;
    for(int i=0;i<g3.size()-needed;i++)sum += g3[i];
    sum += (ll)mid * needed;
    return sum <= s;
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&s);
        for(int i=0;i<n;i++)scanf("%d%d",&l(i),&r(i));
        sort(p,p+n);
        int left = 1,right = 1000000109;
        while(left < right-1)
        {
            int mid = left + (right-left)/2;
            if(valid(mid))left = mid;
            else right = mid;
        }
        printf("%d\n",left);
    }
    return 0;   
}
