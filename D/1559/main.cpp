#include <bits/stdc++.h>

using namespace std;

void makeset(vector<int>& a)
{
    for(int i = 0; i < a.size(); i++) {a[i] = i;}
}

int findparent(int node, vector<int>& a)
{
    if(node == a[node]) return node;
    return a[node] = findparent(a[node], a);
}

void addedge(int u, int v, vector<int>& a, vector<int>& ranks)
{
    u = findparent(u, a);
    v = findparent(v, a);
    if(u == v) return;
    if(ranks[u] < ranks[v]) swap(u, v);
    if(ranks[u] == ranks[v]) ranks[u]++;
    a[v] = u;
}

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> mocha(n + 1), diana(n + 1), mranks(n + 1, 0), dranks(n + 1, 0);
    makeset(mocha); makeset(diana);
    for(int x, y, i = 1; i <= m1 + m2; i++)
    {
        cin >> x >> y;
        if(x > y) swap(x, y);
        if(i <= m1) addedge(x, y, mocha, mranks);
        else addedge(x, y, diana, dranks);
    }
    vector<pair<int, int>> ans;
    for(int i = 1; i + 1 <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(findparent(i, mocha) == findparent(j, mocha) || findparent(i, diana) == findparent(j, diana)) continue;
            addedge(i, j, mocha, mranks);
            addedge(i, j, diana, dranks);
            ans.push_back(make_pair(i, j));
        }
    }
    cout << ans.size() << endl;
    for(auto e : ans) cout << e.first << " " << e.second << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
