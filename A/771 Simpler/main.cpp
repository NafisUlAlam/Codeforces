#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(ll node, vector<vector<ll>>& a, ll& v, ll& e, vector<bool>& visited)
{
    visited[node] = true;
    v++;
    e += a[node].size();
    for(auto child : a[node])
    {
        if(visited[child] == true) continue;
        dfs(child, a, v, e, visited);
    }
}

void solve()
{
    ll n, m, ans;
    cin >> n >> m;
    vector<vector<ll>> a(n);
    vector<bool> visited(n, false);
    for(ll x, y, i = 0; i < m; i++)
    {
        cin >> x >> y;
        --x; --y;
        if(x > y) swap(x, y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(ll i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            ll v = 0, e = 0;
            dfs(i, a, v, e, visited);
            if(v * 1ll * (v - 1) != e)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;

}

int main()
{
    solve();
}
