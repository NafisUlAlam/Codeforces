#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 998244353;
ll c(ll n, ll r)
{
    ll ans = 1;
    for(ll i = n, j = 1; j <= r; j++, i--)
    {
        ans = (ans * i) / j;
    }
    return ans;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    if(r < 2 * l)
    {
        cout << 1 << " " << r - l + 1 << endl;
        return;
    }
    ll p = r / l, copyp = p, power = 0, leftmost = 0;
    while(p)
    {
        if(p & 1)
        {
            leftmost = power;
        }
        power++;
        p = p >> 1;
    }
    //cout << leftmost << endl;
    vector<ll> a(4, 0);
    a[2] = leftmost;
    ll sz = leftmost + 1, ans = 0;
    ll curr = (ll)pow(2, leftmost);
    while(curr <= copyp && a[2] >= 0)
    {
        ll total = a[2] + a[3];
        ll combi = c(total, a[2]);
        ll howmany = (r / curr) - l + 1;
        ll toadd = ( (combi % mod) * (howmany % mod) ) % mod;
        ans = (ans + toadd) % mod;
        curr /= 2;
        curr *= 3;
        a[2]--;
        a[3]++;
    }
    cout << sz << " " << ans << endl;
}


int main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
    //for(int i = 0; i <= 20; i++)cout << c(20, i) << endl;
}
