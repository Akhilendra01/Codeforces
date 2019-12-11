#include <bits/stdc++.h>
using namespace std;
 
int t,b,p,f,h,c,n,cost;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> t;
    while(t--)
    {
        cin >> b >> p >> f >> h >> c;
        if(h > c){
            swap(p,f);
            swap(h,c);
        }
        b>>=1;
        n = min(f,b);
        cost = n*c;
        b-=n;
 
        n = min(p,b);
        cost += n*h;
        cout << cost << endl;
    }
    return 0;
}
