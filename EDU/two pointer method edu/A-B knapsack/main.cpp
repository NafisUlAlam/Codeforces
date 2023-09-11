#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, m, s, a, b;
    cin >> n >> m >> s >> a >> b;
    vector<ll>fi(n), se(m), fis(n + 1, 0), ses(m + 1, 0);
    for(auto & e : fi) cin >> e;
    for(auto & e : se) cin >> e;
    sort(fi.begin(), fi.end());
    sort(se.begin(), se.end());

    fis[n - 1] = fi[n - 1];
    ses[m - 1] = se[m - 1];
    for(int i = n - 2; i >= 0; i--) fis[i] = fis[i + 1] + fi[i];
    for(int i = m - 2; i >= 0; i--) ses[i] = ses[i + 1] + se[i];

    //for(auto elem : fis) cout << elem << " "; cout << endl;
    //for(auto elem : ses) cout << elem << " "; cout << endl;
    ll ans = 0;
    int ib = 0;
    for(ib = 0; (ib * 1ll * b) <= s && (m - ib) >= 0; ib++)
    {
        ll need  = (s - (ib * 1ll * b)) / a;
        ll tosee = max(n - need, 0ll);
        ll cost = ses[m - ib] + 0ll + fis[tosee];
        //cout << ib << " " << tosee << " " << cost <<  endl;
        ans = max(ans, cost);
    }
    cout << ans << endl;
}


int main()
{
    solve();
}
