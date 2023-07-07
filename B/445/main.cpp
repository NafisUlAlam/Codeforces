#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll bfs(ll i, vector<bool>& visited, vector<vector<ll>>& a)
{
    queue<ll> q;
    vector<ll> comp;
    q.push(i);
    visited[i] = true;
    while(!q.empty())
    {
        ll curr = q.front();
        q.pop();
        comp.push_back(curr);
        for(auto e : a[curr])
        {
            if(!visited[e])
            {
                q.push(e);
                visited[e] = true;
            }
        }
    }
    //for(auto e : comp) cout << e << " "; cout << endl;
    return comp.size();
}


void solve()
{
    ll n, m, x, y, ans = 1;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1);
    vector<ll> power(52, 1);
    power[0] = 1;
    for(int i = 1; i < 52; i++) power[i] = power[i - 1] * 2ll;
    vector<bool> visited(n + 1, false);
    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            ll total = bfs(i, visited, a);
            ans *= power[total - 1];
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //while(true)
        solve();
}
