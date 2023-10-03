#include <bits/stdc++.h>

using namespace std;

int dfs(int node, int parent, vector<vector<pair<int, int>>>& a)
{
    int maxi = 0;
    bool flag = false;
    for(auto e : a[node])
    {
        int child = e.first;
        int weight = e.second;
        if(parent == child) continue;
        flag = true;
        maxi = max(maxi, dfs(child, node, a)+ weight);
    }

    if(flag == false) return 0;
    else return maxi;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n);
    for(int u, v, w, i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }
    //for(auto e : a)
    {
        //for(auto e2 : e)
            //cout << "(" << e2.first << " " << e2.second<<")"; cout << endl;
    }
    int ans = dfs(0, -1, a);
    cout << ans << endl;
}

int main()
{
    solve();
}
