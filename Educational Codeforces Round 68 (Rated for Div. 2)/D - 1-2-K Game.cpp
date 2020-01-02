#include <bits/stdc++.h>
using namespace std;
 
int t,n,k;
 
int main(){
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        bool aliceWin = true;
        if(k%3)aliceWin = n%3;
        else{
            int np = n % (k + 1);
            if(np % 3 == 0 && np != k)
			    aliceWin = false;
        }
        puts(aliceWin ? "Alice" : "Bob");
    }
    return 0;
}
