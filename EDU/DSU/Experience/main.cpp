#include <bits/stdc++.h>

using namespace std;

int getparent(int node, vector<int>& a)
{
    if(a[node] == node) return node;
    return getparent(a[node], a);
}

void add(int node, int val, vector<int>& a, vector<int>& sizes, vector<int>& single, vector<int>& doble)
{
    int p = getparent(node, a);
    doble[p] += val;
}

void join(int u, int v, vector<int>& a, vector<int>& sizes, vector<int>& single, vector<int>& doble)
{
    u = getparent(u, a);
    v = getparent(v, a);
    if(u == v) return;
    if(sizes[u] < sizes[v]) swap(u, v);
    a[v] = u;
    doble[v] -= doble[u];
    sizes[u] += sizes[v];
}

int get(int v, vector<int>& a, vector<int>& sizes, vector<int>& single, vector<int>& doble)
{
    if(a[v] == v) return doble[v];
    int val = get(a[v], a, sizes, single, doble);
    return val + doble[v];

}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), sizes(n, 1), single(n, 0), doble(n, 0);
    for(int i = 0; i < n; i++) a[i] = i;
    for(int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        if(s == "add")
        {
            int u, v;
            cin >> u >> v;
            --u; v;
            add(u, v, a, sizes, single, doble);
        }
        else if(s == "join")
        {
            int u, v;
            cin >> u >> v;
            --u; --v;
            join(u, v, a, sizes, single, doble);
        }
        else
        {
            int u;
            cin >> u;
            --u;
            cout << get(u, a, sizes, single, doble) << endl;;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
