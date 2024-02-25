#include <bits/stdc++.h>

using namespace std;

int dfs(int node, int par, vector<vector<pair<int, int>>>& a)
{
    int ans = INT_MAX;
    bool f = false;
    for(auto child : a[node])
    {
        int c = child.first;
        int w = child.second;
        if(c == par) continue;
        f = true;
        ans = min(ans, dfs(c, node, a) + w);
    }
    if(f == false) return 0;
    else return ans;
}

void ad(int node, int par, int sum, int& ans, vector<vector<pair<int, int>>>& a)
{
    bool f = false;
    for(auto child : a[node])
    {
        int c = child.first;
        int w = child.second;
        if(c == par) continue;
        f = true;
        ad(c, node, sum + w, ans, a);
    }
    if(f == false) ans = min(ans, sum);
}

void solve()
{
    int n; string s;
    cin >> n >> s;
    vector<vector<pair<int, int>>> a(n);
    for(int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        --x; --y;
        int w1 = (s[i] == 'L'? 0 : 1);
        int w2 = (s[i] == 'R'? 0 : 1);
        if(x >= 0)a[i].push_back(make_pair(x, w1));
        if(y >= 0)a[i].push_back(make_pair(y, w2));
        if(x >= 0)a[x].push_back(make_pair(i, w1));
        if(y >= 0)a[y].push_back(make_pair(i, w2));
    }

//    for(auto e : a)
//    {
//        for(auto e2 : e) cout << "(" <<e2.first << " " << e2.second << ")"; cout << endl;
//
//    }
    //cout << dfs(0, -1, a) << endl;
    int ans = INT_MAX;
    ad(0, -1, 0, ans, a);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
