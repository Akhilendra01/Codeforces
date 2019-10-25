#include<bits/stdc++.h>
using namespace std;
 
int q,n,cnt1,cnt0,even,odd;
vector<string> arr(55);
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //------------------------------
    cin >> q;
    while(q--)
    {
        cin >> n;
        cnt1 = cnt0 = 0;
        even = odd = 0;
        int neededCouple = 0;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            for(int j=0;j<arr[i].length();j++)
            {
                if(arr[i][j] == '1')cnt1++;
                else cnt0++;
            }
            if(arr[i].length()%2)odd++;
            else {
                even++;
                }    neededCouple += arr[i].length()/2;
            
        }
        int couples = cnt1 / 2 + cnt0 / 2;
        int single = cnt1%2 + cnt0%2;
        cout << (n - (neededCouple > couples?1:0)) << endl;
    }
    return 0;
}
