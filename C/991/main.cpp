#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll mid, ll n)
{
    int turn = 0;
    ll a = 0, b = 0;
    while(n > 0)
    {
        if(turn == 0)
        {
            ll rem = min(n, mid);
            a += rem;
            n -= rem;
        }
        else
        {
            b += n / 10;
            n -= n / 10;
        }
        turn ^= 1;
    }
    //cout << mid << " " << a << " " << b << endl;
    return a >= b;
}

void solve()
{
    ll n, ans = -1;
    cin >> n;
    ll lo = 1, hi = 1e18;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if(check(mid, n))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    //while(1)
    solve();
}
