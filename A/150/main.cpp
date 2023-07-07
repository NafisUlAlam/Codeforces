#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            ll f = i;
            ll s = 0;
            while(n % i == 0)
            {
                n /= i;
                s++;
            }
            a.push_back(make_pair(f, s));
        }
    }
    if(n > 1) a.push_back(make_pair(n, 1));
    ll p = 0;
    for(auto e : a) p += e.second;
    if(p == 2) cout << 2 << endl;
    else if(p <= 1) cout << 1 << endl << 0 << endl;
    else
    {
        ll ans = 1;
        sort(a.begin(), a.end(), [](pair<ll, ll> x, pair<ll, ll> y)
             {
                 return x.second > y.second;
             });
        if(a[0].second > 1) ans = a[0].first * a[0].first;
        else ans = a[0].first * a[1].first;
        cout << 1 << endl << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
