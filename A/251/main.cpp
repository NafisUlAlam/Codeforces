#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll C(int n, int r)
{
    if(n < r) return 0;
    ll ans = 1;
    for(ll i = n, j = 1; j <= r; j++, i--)
    {
        ans = (ans * 1ll * i) / j;
    }
    return ans;
}

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int idx = upper_bound(a.begin(), a.end(), a[i] + d) - a.begin();
        idx -= 1;
        int howmany = idx - i;
        ans += C(howmany, 2);
    }

    cout << ans << endl;
}

int main()
{
    solve();
}
