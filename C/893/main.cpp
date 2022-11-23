#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll dfs(ll node, ll parent, vector<vector<ll>>& g, vector<bool>& visited, vector<ll>& a, ll n)
{
    visited[node] = true;
    ll mini = a[node];
    for(auto child : g[node])
    {
        if(child == parent || visited[child] == true) continue;
        mini = min(mini, dfs(child, node, g, visited, a, n));
    }
    return mini;
}

ll dfsUtil(vector<vector<ll>>& g, vector<bool>& visited, vector<ll>& a, ll n)
{
    ll total = 0;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
            ll ans = dfs(i, -1, g, visited, a, n);
            total += ans;
        }
    }
    return total;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<vector<ll>> g(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> visited(n + 1, false);
    ll ans = dfsUtil(g, visited, a, n);
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
