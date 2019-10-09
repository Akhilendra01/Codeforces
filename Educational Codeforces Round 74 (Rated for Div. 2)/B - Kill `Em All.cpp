#include <bits/stdc++.h>
 
using namespace std;
 
int t,n,r,m;
 
int main() {
    cin >> t;
    while(t--)
    {
        cin >> n >> r;
        vector<bool> count(100005,0);
        vector<int> pos;
        for(int i=0;i<n;i++)
        {
            cin >> m;
            if(!count[m])
            {
                count[m] = 1;
                pos.push_back(m);
            }
        }
        sort(pos.begin(),pos.end(),greater<int>());
        int shift = 0;int i=0;
        for(;i<pos.size();i++)
        {
            if(pos[i]+shift<=0)
                break;
            shift -= r;
        }
         cout << i << endl;
    }
	return 0;
} 
