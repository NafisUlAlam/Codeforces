#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<pair<int, int>>& g, int mini, array<int, 3>& curr)
{
    int child = g[node].first;
    int dia = g[node].second;
    //cout << node + 1 << " " << child + 1 << " " << mini << " " << dia << endl;
    if(child == -1)
    {
        curr[1] = node + 1;
        curr[2] = mini;
        return;
    }
    mini = min(mini, dia);
    dfs(child, g, mini, curr);
}

void solve()
{
    int n, p, a, b, d;
    cin >> n >> p;
    vector<int> in(n, 0), out(n, 0);
    vector<pair<int, int>>g(n, make_pair(-1, -1));
    for(int i = 1; i <= p; i++)
    {
        cin >> a >> b >> d;
        g[--a] = make_pair(--b, d);
        in[b]++;
    }
    //for(auto e : g) cout << "( "<<e.first + 1 << " " << e.second << ")"; cout << endl;
    vector<array<int, 3>> ans;
    for(int i = 0; i < n; i++)
    {
        if(in[i] != 0) continue;
        int mini = INT_MAX;
        array<int, 3> curr = {i + 1, -1, -1};
        dfs(i, g, mini, curr);
        if(curr[0] != curr[1])ans.push_back(curr);
    }
    //sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto e : ans)
    {
        for(auto e2 : e) cout << e2 << " "; cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
