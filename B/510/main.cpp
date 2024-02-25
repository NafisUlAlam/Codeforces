#include <bits/stdc++.h>

using namespace std;

void dfs(int x, int y, vector<vector<int>>& a, vector<vector<bool>>& visited, int& nodes, int& degrees)
{
    nodes++;
    visited[x][y] = true;
    if(x - 1 >= 0 && a[x - 1][y] == a[x][y]) degrees++;
    if(x + 1 < a.size() && a[x + 1][y] == a[x][y]) degrees++;
    if(y - 1 >= 0 && a[x][y - 1] == a[x][y]) degrees++;
    if(y + 1 < a[x].size() && a[x][y + 1] == a[x][y]) degrees++;

    if(x - 1 >= 0 && a[x - 1][y] == a[x][y] && visited[x - 1][y] == false) dfs(x - 1, y, a, visited, nodes, degrees);
    if(x + 1 < a.size() && a[x + 1][y] == a[x][y] && visited[x + 1][y] == false) dfs(x + 1, y, a, visited, nodes, degrees);
    if(y - 1 >= 0 && a[x][y - 1] == a[x][y] && visited[x][y - 1] == false) dfs(x, y - 1, a, visited, nodes, degrees);
    if(y + 1 < a[x].size() && a[x][y + 1] == a[x][y] && visited[x][y + 1] == false) dfs(x, y + 1, a, visited, nodes, degrees);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) a[i][j] = s[j] - 'A';
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] == false)
            {
                int nodes = 0, degrees = 0;
                dfs(i, j, a, visited, nodes, degrees);
                //cout << nodes << " " << degrees << endl;
                if(degrees >= 2 * nodes)
                {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;

}

int main()
{
    solve();
}
