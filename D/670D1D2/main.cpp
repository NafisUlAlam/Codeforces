#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll mid, vector<ll>& a, vector<ll>& b, ll k)
{
    for(int i = 0; i < (int) a.size(); i++)
    {
        ll need = a[i] * mid;
        if(need > b[i])
        {
            if(need - b[i] <= k)
            {
                k -= need - b[i];
            }
            else return false;
        }
    }
    //cout << (double)mid << " true " << endl;
    return true;
}

void solve()
{
    ll n, k, ans = -1;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    ll l = 0, h = (ll) 3e9;
    while(l <= h)
    {
        ll mid = (l + h) / 2;
        if(check(mid, a, b, k))
        {
            ans = mid;
            l = mid + 1;
        }
        else h = mid - 1;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //while(true)
    solve();
}
