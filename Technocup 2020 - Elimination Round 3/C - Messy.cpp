#include <bits/stdc++.h>
using namespace std;
 
int t,n,k;
char s[2003];
vector<pair<int,int>> swaps;
void swapRange(int l,int r)
{
    int m = r-l;
    for(int i=0;i<=m/2;i++)swap(s[l+i],s[l+m-i]);
    swaps.push_back(make_pair(l+1,r+1));
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
        swaps.clear();
        scanf("%d%d%s",&n,&k,s);
        int l = 0,_;
        for(l = 0,_=0;l < n&&_<k-1;l++)
        {
            if(l%2)
            {
                int r;
                if(s[l] != ')')
                {
                    for(r=l+1;r<n;r++)if(s[r] == ')')break;
                    swapRange(l,r);
                }
                _++;
            }else{
                int r;
                if(s[l] != '(')
                {
                    for(r=l+1;r<n;r++)if(s[r] == '(')break;
                    swapRange(l,r);
                }
            }
        }
 
        int m = (n - l - 1)/2;
        for(int i = 0;i <= m;i++)
        {
            int r;
            if(s[l+i] != '(')
            {
                for(r=l+i+1;r<n;r++)if(s[r] == '(')break;
                swapRange(l+i,r);
            }
        }
        printf("%d\n",(int)swaps.size());
        for(auto swp:swaps)printf("%d %d\n",swp.first,swp.second);
    }
    return 0;
}
