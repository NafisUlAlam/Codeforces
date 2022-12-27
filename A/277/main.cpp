#include <bits/stdc++.h>

using namespace std;

int findparent(int node, vector<int>& parent)
{
    if(parent[node] == node) return node;
    return parent[node] = findparent(parent[node], parent);
}

void uni(int node1, int node2, vector<int>& parent,  vector<int>& depth)
{
    int p1 = findparent(node1, parent);
    int p2 = findparent(node2, parent);
    if(p1 == p2) return;

    if(depth[p1] == depth[p2])depth[p1]++;
    else if(depth[p1] < depth[p2]) swap(p1, p2);
    parent[p2] = p1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m + 1);
    vector<int> parent(n + 1), depth(n + 1, 0);
    for(int i = 1; i <= n; i++) parent[i] = i;
    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == 0) {ans++; parent[i] = 0;}
        for(int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            a[y].push_back(i);
        }
    }
    for(int i = 1; i <= m; i++) sort(a[i].begin(), a[i].end());

    for(int i = 1; i <= m; i++)
    {
        int sz = a[i].size();
        if(sz >= 2)
        {
            int f = a[i][0];
            for(int j = 1; j < sz; j++)
            {
                uni(f, a[i][j], parent, depth);
            }
        }
    }
    //for(int i = 1; i <= n; i++) cout << " (node " << i << " parent "<< parent[i] << " depth " << depth[i] <<" ) "; cout << endl;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(parent[i] == i) cnt++;
    }

    cout << ans + max(cnt - 1, 0) << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)
    {
        solve();
    }
}
