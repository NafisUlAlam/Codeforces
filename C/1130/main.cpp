#include <bits/stdc++.h>
using namespace std;

bool isvalid(int i, int j, vector<vector<int>>& a, vector<vector<int>>& visited)
{
    if(i < 0 || j < 0 || i >= a.size() || j >= a.size() || a[i][j] == 0 || visited[i][j] == 1) return false;
    return true;
}
void dfs(int i, int j, vector<pair<int, int>>& component, vector<vector<pair<int, int>>>& components, vector<vector<int>>& a, vector<vector<int>>& visited)
{
    visited[i][j] = 1;
    component.push_back(make_pair(i, j));
    if(isvalid(i - 1, j, a, visited)) dfs(i - 1, j, component, components, a, visited);
    if(isvalid(i + 1, j, a, visited)) dfs(i + 1, j, component, components, a, visited);
    if(isvalid(i, j - 1, a, visited)) dfs(i, j - 1, component, components, a, visited);
    if(isvalid(i, j + 1, a, visited)) dfs(i, j + 1, component, components, a, visited);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pos(2);
    vector<vector<int>> a(n, vector<int> (n)), visited(n, vector<int> (n, 0));
    for(int x, y, i = 0; i <= 1; i++)
    {
        cin >> x >> y;
        pos[i] = make_pair(--x, --y);
    }
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) a[i][j] = 1 - (s[j] - '0');
    }

    vector<vector<pair<int, int>>> components;
    for(auto e : pos)
    {
        int i = e.first;
        int j = e.second;
        if(visited[i][j] == 1) continue;
        vector<pair<int, int>> component;
        dfs(i, j, component, components, a, visited);
        components.push_back(component);
    }
//    for(auto e : components)
//    {
//        for(auto e2 : e) cout << "( " << e2.first << " " << e2.second << ")"; cout << endl;
//    }
    if(components.size() == 1) cout << 0 << endl;
    else
    {
        int ans = INT_MAX;
        for(auto e : components[0])
        {
            int x1 = e.first;
            int y1 = e.second;
            for(auto e2 : components[1])
            {
                int x2 = e2.first;
                int y2 = e2.second;
                ans = min(ans, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            }
        }
        cout << ans << endl;
    }

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
