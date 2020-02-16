#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll tc=1,a,b,c,minx,maxx,miny,maxy,x,y,g;

ll gcd(ll a_, ll b_, ll &x0, ll &y0) {
    if (a_ == 0) {
        x0 = 0; y0 = 1;
        return b_;
    }
    ll x1, y1;
    ll d = gcd(b_%a_, a_, x1, y1);
    x0 = y1 - (b_ / a_) * x1;
    y0 = x1;
    return d;
}

bool find_any_solution() {
    g = gcd(abs(a), abs(b), x, y);
    if (c % g) {
        return false;
    }

    x *= c / g;
    y *= c / g;

    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

void shift_solution(ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions() {
    if (!find_any_solution())
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution((minx - x) / b);
    if (x < minx)
        shift_solution(sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution((maxx - x) / b);
    if (x > maxx)
        shift_solution(-sign_b);
    ll rx1 = x;

    shift_solution(-(miny - y) / a);
    if (y < miny)
        shift_solution(-sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(-(maxy - y) / a);
    if (y > maxy)
        shift_solution(sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%lld",&tc);
}

void input()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    c = -c;
    scanf("%lld%lld%lld%lld",&minx,&maxx,&miny,&maxy);
}

void solve()
{   
    if(!a && !b)
        printf("%lld\n",c?0:(maxx-minx+1)*(maxy-miny+1));
    else if(!a)
        printf("%lld\n",(c%b == 0) && miny <= (c/b) && (c/b) <= maxy ? (maxx-minx+1):0);
    else if(!b)
        printf("%lld\n",(c%a == 0) && minx <= (c/a) && (c/a) <= maxx ? (maxy-miny+1):0);
    else
        printf("%lld\n",find_all_solutions());
}

int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
