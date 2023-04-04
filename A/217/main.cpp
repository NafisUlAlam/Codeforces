#include <bits/stdc++.h>

using namespace std;

vector<int> p(1000 + 1, -1), ranks(1000 + 1, 0);

int findParent(int u)
{
    if(u == p[u] || u == -1) return u;
    return p[u] = findParent(p[u]);
}

void join(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if(u == v) return;
    if(ranks[u] == ranks[v]) ranks[u]++;
    else if(ranks[u] < ranks[v]) swap(u, v);
    p[v] = u;
}

void solve()
{
    p.assign(1001, -1);
    ranks.assign(1001, 0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
        //p[x] = x;
        p[y] = y;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i + 1 < n; i++)
    {
        if(a[i].first == a[i + 1].first)
        {
            join(a[i].second, a[i + 1].second);
        }
    }
    for(int i = 1; i <= 1000; i++) findParent(i);
    int ans = 0;
    for(int i = 1; i <= 1000; i++)
    {
        if(p[i] == -1) continue;
        if(p[i] == i) ans++;
    }
    cout << ans - 1 << endl;
}

int main()
{
    int t = 1;
    while(t--) solve();
}
