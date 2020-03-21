#include<bits/stdc++.h>
using namespace std;

int tc=1,n,arr[102];

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&tc);
}

void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
}

void output()
{
    arr[0] = 0;
    int odd = 0,even = 0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i-1]%2&&arr[i]%2)
            odd = i;
        if(arr[i]%2==0)
            even = i;
    }

    if(odd)
        printf("2\n%d %d\n",odd-1,odd);
    else if(even)
        printf("1\n%d\n",even);
    else
        printf("-1\n");
}

int main()
{
    preprocess();
    while(tc--)
    {
        input();
        output();
    }
    return 0;
}
