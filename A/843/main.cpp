#include <bits/stdc++.h>

using namespace std;

int find_parent(int u, vector<int>& p)
{
    if(u == p[u]) return u;
    int val = find_parent(p[u], p);
    p[u] = val;
    return val;
}

void join(int u, int v, vector<int>& p, vector<int>& ranks)
{
    u = find_parent(u, p);
    v = find_parent(v, p);
    if(u == v) return;
    if(ranks[u] < ranks[v]) swap(u, v);
    p[v] = u;
    if(ranks[u] == ranks[v]) ranks[u] += 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), ranks(n + 1, 0), visited(n + 1, 0);
    vector<pair<int, int>> a(n + 1);
    //a[0] = make_pair(INT_MIN, 0);
    for(int x, i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = make_pair(x, i);
        p[i] = i;
    }
    sort(a.begin() + 1, a.end());
    //for(int i = 1; i <= n; i++) cout << "("<<a[i].first << " " << a[i].second << " )"; cout << endl;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] > 0) continue;
        int u = i, v = a[u].second;
        while(visited[u] == 0)
        {
            visited[u] = 1;
            v = a[u].second;
            //cout << "joining " << u << " " << v << endl;
            join(u, v, p, ranks);
            u = v;
        }
    }
    //for(int i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;
    vector<vector<int>> ans(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(ans[p[i]].size() == 0) cnt++;
        ans[p[i]].push_back(i);
    }

    cout << cnt << endl;
    for(int i = 1; i <= n; i++)
    {
        if(ans[i].size() == 0) continue;
        cout << ans[i].size() << " ";
        for(auto e : ans[i]) cout << e << " "; cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
