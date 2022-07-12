#include <bits/stdc++.h>
#define ll long long

using namespace std;


bool isBipartite(vector<vector<int>>& adj, int n)
{
    vector<int> color(n, - 1);
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++)
    {
        if(color[i] == -1)
        {
            q.push({i, 0});
            color[i] = 0;
            while(!q.empty())
            {
                int vertex = q.front().first;
                int col = q.front().second;
                q.pop();

                for(auto neighbor : adj[vertex])
                {
                    if(color[neighbor] == col)
                    {
                        return false;
                    }
                    if(color[neighbor] == -1)
                    {
                        color[neighbor] = (col == 0)? 1 : 0;
                        q.push({neighbor, color[neighbor]});
                    }
                }
            }
        }
    }
    return true;
}



bool isBipartite2(vector<vector<int>>&adj, int n)
{
    vector<int> color(n, -1);
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        if(color[i] == -1)
        {
            color[i] = 0;
            q.push({i, color[i]});
            while(!q.empty())
            {
                int vertex = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto neighbor : adj[vertex])
                {
                    if(color[neighbor] == -1)
                    {
                        color[neighbor] = (col == 0)? 1 : 0;
                        q.push({neighbor, color[neighbor]});
                    }
                    if(color[neighbor] == col)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<int>>adj(n);
    bool ok = true;

    for(ll i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if(x == y || adj[x].size() > 2 || adj[y].size() > 2)
        {
            ok = false;
            //break;
        }
    }


    if(ok == false)
    {
        cout << "from ok NO" << endl;
        return;
    }

    ok = isBipartite2(adj, n);
    if(ok == true)
    {
        cout << "from bipartite YES" << endl;
        return;
    }
    else cout << "from bipartite NO" << endl;

}





int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}
