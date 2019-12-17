#include <bits/stdc++.h>
using namespace std;
 
int t,a,b,c;
 
bool isValid(int mid)
{
    int x = a,y = b,z = c;
    if(a >= mid)
    {
        int giveToB = a - mid;
        assert(giveToB >= 0);
        int giveToC = max(b+giveToB - mid , 0);
        if(giveToC > b || giveToC + c > mid)return false;
    }else{
        int giveToC = b - mid;
        assert(giveToC >= 0);
        int giveToA = max(c+giveToC - mid, 0);
        if(giveToA + a > mid)return 0;
    }
    return true;
}
 
int main(){
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a < c)swap(a,c);
        int l = max((a+b+c)/3,c),r = max(a,b)+1,ans;
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(isValid(mid)){
                ans = mid;
                r = mid;
            }else l = mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
