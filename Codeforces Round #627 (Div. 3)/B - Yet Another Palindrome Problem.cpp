#include<bits/stdc++.h>
using namespace std;

int tc=1,n,arr[5003];

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}

void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
}

void solve()
{
    bool flag = false;
    for(int i=0;i<n && !flag;i++)
    {
        for(int j=i+2;j<n && !flag;j++)
        {
            if(arr[i] == arr[j])
                flag = true;
        }
    }
    puts(flag?"YES":"NO");
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
