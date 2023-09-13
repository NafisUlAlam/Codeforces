#include <bits/stdc++.h>

using namespace std;

int getparent(int node, vector<int>& a)
{
    if(a[node] == node) return node;
    int val = getparent(a[node], a);
    a[node] = val;
    return val;

}

void join(int u, int v, vector<int>& a, vector<int>& ranks)
{
    u = getparent(u, a);
    v = getparent(v, a);
    if(u == v) return;
    if(ranks[u] < ranks[v]) swap(u, v);
    if(ranks[u] == ranks[v]) ranks[u]++;
    a[v] = u;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), ranks(n, 0);
    for(int i = 0; i < n; i++) a[i] = i;
    vector<pair<string, pair<int, int>>> queries;
    vector<string> ans;
    for(int i = 1, x, y; i <= m; i++)cin >> x >> y;
    for(int i = 1; i <= k; i++)
    {
        int x, y; string s;
        cin >> s >> x >> y;
        queries.push_back(make_pair(s, make_pair(--x, --y)));
    }
    reverse(queries.begin(), queries.end());
    for(auto e : queries)
    {
        string s = e.first;
        int x = e.second.first;
        int y = e.second.second;
        if(s == "cut") join(x, y, a, ranks);
        else
        {
            if(getparent(x, a) == getparent(y, a)) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto e: ans) cout << e << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
