
#include <bits/stdc++.h>
#define INF 998244353
using namespace std;
 
int t=1,n,arr[102],cnt[2]={0};
bool flag[105] = {0};
 
int cost(vector<int> regions,int& total);
int both_before(vector<int> regions,vector<int> borders,int total);
int both_after(vector<int> regions,vector<int> borders,int total);
int one_before_one_after(vector<int> regions,vector<int> borders,int total);
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
}
 
void solve()
{
    if(n == 1){
        printf("0\n");return;
    }
    for(int i=0;i<n;i++)flag[arr[i]] = 1;
    for(int i=1;i<=n;i++)if(!flag[i])cnt[i%2]++;
    int res = 0;
    for(int i=1;i<n;i++)if(arr[i] && arr[i-1])res += (arr[i]%2) != (arr[i-1]%2);
    int last = -1,len = 0;
    vector<int> evens,odds,even_borders,odd_borders;
    for(int i=0;i<n;i++)
    {
        if(arr[i])
        {
            if(len){
                if(last == -1){
                    if(arr[i] % 2)odd_borders.push_back(len);
                    else even_borders.push_back(len);
                }else{
                    if(arr[i] % 2){
                        if(last)odds.push_back(len);
                        else res++;
                    }else{
                        if(!last)evens.push_back(len);
                        else res++;
                    }
                }
                len = 0;    
            }
            last = arr[i]%2;
        }else len++;
    }
    if(len){
        if(last == -1){
            printf("1\n");return;
        }else{
            if(last % 2)odd_borders.push_back(len);
            else even_borders.push_back(len);
        }   
    }
    
    sort(evens.begin(),evens.end());
    sort(odds.begin(),odds.end());
    sort(even_borders.begin(),even_borders.end());
    sort(odd_borders.begin(),odd_borders.end());
 
    res += min(min( both_before(evens,even_borders,cnt[0]) , both_after(evens,even_borders,cnt[0]) ), one_before_one_after(evens,even_borders,cnt[0]) );
    res += min(min( both_before(odds,odd_borders,cnt[1]) , both_after(odds,odd_borders,cnt[1]) ), one_before_one_after(odds,odd_borders,cnt[1]) );
    printf("%d\n",res);
}
 
int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
 
int cost(vector<int> regions,int& total)
{
    int m = regions.size(),i=0;
    for(;i<m && regions[i] <= total;i++)total -= regions[i];
    return m-i;
}
 
int both_before(vector<int> regions,vector<int> borders,int total)
{
    int res = cost(borders,total);
    res += 2*cost(regions,total);
    return res;
}
 
 
int both_after(vector<int> regions,vector<int> borders,int total)
{
    int res = 2*cost(regions,total);
    res += cost(borders,total);
    return res;
}
 
int one_before_one_after(vector<int> regions,vector<int> borders,int total)
{
    int res = 0;
    if(borders.size() > 0){
        if(borders[0] > total)res++;
        else total -= borders[0];
    }
    res += 2*cost(regions,total);
    if(borders.size() > 1)if(borders[1] > total)res++;
    return res;
}
