#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Publication
{
    ll a,t;
};


struct less_than_key
{
    inline bool operator() (const Publication& struct1, const Publication& struct2)
    {
        return struct1.a == struct2.a?struct1.t > struct2.t:struct1.a < struct2.a;
    }
};

int tc=1,n;
vector<Publication> arr;


void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&tc);
}

void input()
{
    scanf("%d",&n);
    arr.resize(n);
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i].a);
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i].t);
}

void solve()
{
    sort(arr.begin(),arr.end(),less_than_key());
    priority_queue<pair<ll,ll>> pq;
    ll ans = 0,curr;
    for(int i=1;i<n;i++)
    {
        curr = arr[i].a;
        if(arr[i].a == arr[i-1].a)
            pq.push(make_pair(arr[i].t,-arr[i].a));
        else if((!pq.empty()) && arr[i].t < pq.top().first)
        {
            ans += pq.top().first * (curr + pq.top().second);
            pq.pop();
            pq.push(make_pair(arr[i].t,-arr[i].a));
        }
        

        curr++;
        while((i==n-1 || curr < arr[i+1].a) && !pq.empty())
        {
            ans += pq.top().first * (curr + pq.top().second);
            pq.pop();
            curr++;
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    preprocess();
    while(tc--)
    {
        input();
        solve();
    }
    return 0;
}
