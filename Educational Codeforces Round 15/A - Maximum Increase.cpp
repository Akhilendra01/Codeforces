#include <iostream>
using namespace std;

int n,t1,t2,ans,mx=1;

int main()
{
    cin >> n >> t1;
    ans = 1;
    for(int i=1;i<n;i++)
    {
        cin >> t2;
        if(t2 > t1)
            ans++;
        else
            ans = 1;
        
        mx = max(mx,ans);
        t1 = t2;
    }
    cout << mx << endl;
    return 0;
}
