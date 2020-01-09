#include <bits/stdc++.h>
#define x first
#define y second
#define INF 10000000
using namespace std;
 
int t=1,n;
pair<int,int> points[100];
 
bool is_on_line(pair<int,int> start,pair<int,int> end,int idx);
bool is_square_without(int idx);
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d",&n);
    n *= 4;n++;
    for(int i=0;i<n;i++)scanf("%d%d",&points[i].x,&points[i].y);
}
 
int solve()
{
    for(int i=0;i<n;i++)
        if(is_square_without(i))
            return printf("%d %d\n",points[i].x,points[i].y);
    assert(0);
    return 0;
}
 
int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
 
 
bool is_on_line(pair<int,int> start,pair<int,int> end,int idx){
    if(start.x == end.x)return points[idx].x == start.x && start.y <= points[idx].y && points[idx].y <= end.y;
    if(start.y == end.y)return points[idx].y == start.y && start.x <= points[idx].x && points[idx].x <= end.x;
    assert(0);
    return 0;
}
bool is_square_without(int idx){
    int minx,miny,maxx,maxy;
    minx = miny = INF;
    maxx = maxy = -INF;
    for(int i=0;i<n;i++)if(i != idx){
        minx = min(minx,points[i].x);
        miny = min(miny,points[i].y);
        maxx = max(maxx,points[i].x);
        maxy = max(maxy,points[i].y);
    }
 
    if(maxx - minx != maxy - miny)return false;
 
    pair<int,int> p1 = make_pair(minx,miny);
    pair<int,int> p2 = make_pair(minx,maxy);
    pair<int,int> p3 = make_pair(maxx,maxy);
    pair<int,int> p4 = make_pair(maxx,miny);
 
    for(int i=0;i<n;i++)if(i!=idx)
    {
        int flag = false;
        if(is_on_line(p1,p2,i))flag = true;
        if(is_on_line(p2,p3,i))flag = true;
        if(is_on_line(p4,p3,i))flag = true;
        if(is_on_line(p1,p4,i))flag = true;
        if(!flag)return false;
    }
    return true;
}
