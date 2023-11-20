#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int>& used, vector<int>& component, vector<vector<int>>& a)
{
    used[node] = 1;
    component.push_back(node);
    for(auto child : a[node])
    {
        if(used[child] == 0) dfs(child, used, component, a);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    vector<int> deg(n, 0), used(n, 0), component;
    for(int x, y, i = 0; i < m; i++)
    {
        cin >> x >> y;
        --x; --y;
        a[x].push_back(y);
        a[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            bool f = true;
            component.clear();
            dfs(i, used, component, a);
            for(auto e : component)
            {
                if(deg[e] != 2) f = false;
            }
            if(f) ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
