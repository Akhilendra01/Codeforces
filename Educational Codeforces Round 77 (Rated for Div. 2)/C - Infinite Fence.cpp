
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll t,r,b,k,g;
 
int main(){
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&r,&b,&k);
        g = __gcd(r,b);
        if(r > b)swap(r,b);
        r/=g;b/=g;
        printf("%s\n",b-1 <= (k-1)*r?"OBEY":"REBEL");
    }
    return 0;
}
