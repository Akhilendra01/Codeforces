#include<bits/stdc++.h>
#define SIZE 200005
using namespace std;

int tc=1,n,color[SIZE],dp[SIZE];
vector<vector<int>> neighbors(SIZE);
vector<set<int>> choosen(SIZE);

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&tc);
}

void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",color+i);
    for(int i=0;i<n-1;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        neighbors[v1].push_back(v2);
        neighbors[v2].push_back(v1);
    }

}

int dfs(int node,int parent)
{
    int ans = color[node]?1:-1;
    for(int neighbor:neighbors[node])
        if(neighbor != parent)
        {
            int curr = ans+dfs(neighbor,node);
            if(curr > ans)
            {
                ans = curr;
                choosen[node].insert(neighbor);
            }
        }

    return dp[node] = ans;
}

int DFS(int node,int parent)
{
    if(parent)
    {
        int par = dp[parent];
        if(choosen[parent].find(node) != choosen[parent].end())
            par -= dp[node];
        dp[node] = max(par+dp[node],dp[node]);
    }
    
    for(int neighbor:neighbors[node])
        if(neighbor != parent)
            DFS(neighbor,node);
}

void solve()
{
    dfs(1,0);
    DFS(1,0);
    for(int i=1;i<=n;i++)
        cout << dp[i] << " ";
    cout << endl;
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
