#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll findparent(ll node, vector<ll>& leader)
{
    if(leader[node] == node) return leader[node];
    ll val = findparent(leader[node], leader);
    leader[node] = val;
    return val;
}

void join(ll u, ll v, vector<ll>& leader, vector<ll>& ranks)
{
    u = findparent(u, leader);
    v = findparent(v, leader);
    if(u == v) return;
    if(ranks[u] < ranks[v]) swap(u, v);
    else if(ranks[u] == ranks[v]) ranks[u]++;
    leader[v] = u;
}

void solve()
{
    ll n, m, ans;
    cin >> n >> m;
    vector<vector<ll>> a(n);
    vector<ll> leader(n), ranks(n, 0);
    for(ll i = 0; i < n; i++) leader[i] = i;

    for(ll x, y, i = 0; i < m; i++)
    {
        cin >> x >> y;
        --x; --y;
        if(x > y) swap(x, y);
        a[x].push_back(y);
        a[y].push_back(x);
        join(x, y, leader, ranks);
    }
    for(int i = 0; i < n; i++) findparent(i, leader);
    vector<pair<ll, ll>> comps(n, make_pair(0, 0));

    for(int i = 0; i < n; i++)
    {
        comps[leader[i]].first += 1;
        comps[leader[i]].second += a[i].size();
    }
    //for(auto e : comps) cout << "( " << e.first << " " << e.second << " )"; cout << endl;
    for(int i = 0; i < n; i++)
    {
        ll x = comps[i].first;
        ll y = comps[i].second;
        if(x * 1ll * (x - 1) != y)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
