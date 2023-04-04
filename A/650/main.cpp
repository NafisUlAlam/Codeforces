#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    map<pair<ll, ll>, ll> mp;
    for(ll i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        pair<ll, ll> pp = make_pair(x[i], y[i]);
        mp[pp]++;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        ll curr = x[i];
        ll idx = upper_bound(x.begin() + i + 1, x.end(), curr) - x.begin();
        ll total = idx - i - 1;
        ans += total;
    }
    for(int i = 0; i < n; i++)
    {
        int curr = y[i];
        int idx = upper_bound(y.begin() + i + 1, y.end(), curr) - y.begin();
        int total = idx - i - 1;
        ans += total;
    }
    for(auto e : mp)
    {
        ll cnt = e.second;
        ans = ans - ( (cnt * (cnt - 1) ) / 2);
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
