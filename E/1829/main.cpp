#include <bits/stdc++.h>

using namespace std;

int bfs(int i, int j, vector<vector<int>>& a, vector<bool>& visited)
{
    //visited[(i * (int)a[i].size() - 1) + j + 1] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    int val = 0;
    while(q.size() > 0)
    {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        //cout << x << " " << y << endl;
        visited[x * (int) a[x].size() + y] = true;
        val += a[x][y];
        if(x - 1 >= 0 && !visited[(x - 1) * (int)a[x - 1].size() + y])
        {
            q.push(make_pair(x - 1, y));
            visited[(x - 1) * (int)a[x - 1].size() + y] = true;
        }
        if(x + 1 < (int)a.size() && !visited[(x + 1) * (int)a[x + 1].size() + y])
        {
            q.push(make_pair(x + 1, y));
            visited[(x + 1) * (int)a[x + 1].size() + y] = true;
        }
        if(y - 1 >= 0 && !visited[(x) * (int)a[x].size() + y - 1])
        {
            q.push(make_pair(x, y - 1));
            visited[(x) * (int)a[x].size() + y - 1] = true;
        }
        if(y + 1 < (int)a[x].size() && !visited[(x) * (int)a[x].size() + y + 1])
        {
            q.push(make_pair(x, y + 1));
            visited[(x) * (int)a[x].size() + y + 1] = true;
        }
        //cout << "hi" << endl;
        //for(auto e : visited) cout << e << " "; cout << endl;
        //sleep(5);
    }
    return val;
}


void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<bool> visited(n * m, false);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0) visited[(i * m) + j] = true;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //cout << i << " " << j << endl;
            int curr = 0;
            if(visited[(i * m) + j] == true) continue;
            curr = bfs(i, j, a, visited);
            ans = max(ans, curr);
        }
    }
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
