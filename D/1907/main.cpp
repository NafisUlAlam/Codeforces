#include <bits/stdc++.h>

using namespace std;

bool check(int mid, vector<pair<int, int>>& a)
{
    int l = 0, r = 0;
    for(int i = 0; i < a.size(); i++)
    {
        l -= mid;
        r += mid;
        l = max(l, a[i].first);
        r = min(r, a[i].second);
        if(l > r) return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    int lo = 0, hi = 1e9, ans = -1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(check(mid, a))
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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
