#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dfs(int u, int curr, int maxi, vector<bool>& restaurants, vector<bool> visited, vector<vector<int>>& a, int m)
{
    visited[u] = true;
    if(restaurants[u] == true) curr++;
    else curr = 0;
    maxi = max(curr, maxi);
    //cout << u << " " << curr << " " << maxi << endl;

    int ans = 0;
    bool flag = false;
    for(auto e : a[u])
    {
        //cout << u << " " << curr << " " << maxi << endl;
        if(visited[e] == true) continue;
        flag = true;
        ans += dfs(e, curr, maxi, restaurants, visited, a, m);
        //cout << u << " " << curr << " " << maxi << endl;
    }
    if(flag == false)
    {
        //cout << "for node " << u << " flag is false " << maxi << endl;
        if(maxi <= m) return ans = 1;
        else return ans = 0;
    }
    else return ans;

}
void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    vector<bool> visited(n + 1, false), restaurants(n + 1, false);
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x == 1) restaurants[i] = true;
    }
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
//    for(auto e : a)
//    {
//        for(auto e2 : e) cout << e2 << " "; cout << endl;
//    }
    ll ans = dfs(1, 0, 0, restaurants, visited, a, m);
    cout << ans << endl;
}

int main()
{
    solve();
}
/*
10
2
1 1 0 1 0 1 0 0 0 0
1 2 2 3 2 4 3 5 3 6 6 7  6 8  4 9 4 10
*/
