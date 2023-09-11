#include <bits/stdc++.h>

using namespace std;

int findparent(int u, vector<int>& a)
{
    if(u == a[u]) return a[u];
    else
    {
        int val = findparent(a[u], a);
        a[u] = val;
        return val;
    }
}

void join(int u, int v, vector<int>& a, vector<int>& ranks)
{
    u = findparent(u, a);
    v = findparent(v, a);
    if(u == v) return;
    if(ranks[u] < ranks[v]) swap(u, v);
    else if(ranks[u] == ranks[v]) ranks[u]++;
    a[v] = u;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), ranks(n, 0);
    for(int i = 0; i < n; i++) a[i] = i;
    for(int i = 1; i <= m; i++)
    {
        string s; int u, v;
        cin >> s >> u >> v;
        u -= 1; v -= 1;
        if(s == "union") join(u, v, a, ranks);
        else
        {
            u = findparent(u, a);
            v = findparent(v, a);
            if(u == v) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
