#include<bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(int node, int parent,vector<int>& a,int& cnt,
         vector<bool>& visited, vector<int> &component)
{
   visited[node] = true;
   cnt++;
   component.push_back(node);
   int child = a[node];
   if(child == parent || child == node || visited[child]) return;
   dfs(child, node, a, cnt, visited, component);
}

void solve1249B2()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), ans(n + 1, 1);
   vector<bool> visited(n + 1, false);
   for(int i = 1; i <= n; i++) cin >> a[i];
   for(int i = 1; i <= n; i++)
   {
      if(visited[i] == false)
      {
         int cnt = 0;
         vector<int> component;
         dfs(i, -1, a, cnt, visited, component);
         for(auto elem : component)
         {
            ans[elem] = cnt;
         }
      }
   }

   for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   cin >> t;
   while(t--)
   {
      solve1249B2();
   }
}

