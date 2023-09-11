#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, int prime, vector<vector<pair<int, int>>>& g, vector<int>& ans)
{
    //cout << "dfs " << node << endl;;
    for(auto child : g[node])
    {
        if(child.first == parent) continue;
        ans[child.second] = prime;
        if(prime == 2) dfs(child.first, node, 11, g, ans);
        else dfs(child.first, node, 2, g, ans);
        if(prime == 2) prime = 11;
        else prime = 2;
        //cout << node << " return " << child.first << " " << prime << endl;
    }
}

void solve1627C()
{
   int n, x, y;
   cin >> n;
   vector<int> cnt(n + 1, 0), ans(n, -1);
   vector<vector<pair<int, int>>> g(n + 1);
   for(int i = 1; i <= n - 1; i++)
   {
      cin >> x >> y;
      if(x < n + 1 && y < n + 1) {cnt[x]++; cnt[y]++;}
      g[x].push_back(make_pair(y, i));
      g[y].push_back(make_pair(x, i));
   }
   for(int i = 1; i <= n; i++)
   {
      if(cnt[i] > 2)
      {
         cout << -1 << endl;
         return;
      }
   }
   dfs(1, -1, 2, g, ans);
   for(int i = 1; i <= n - 1; i++) cout << ans[i] << " "; cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve1627C();
}
