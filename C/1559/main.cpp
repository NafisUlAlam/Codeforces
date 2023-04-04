#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, vector<int>& ans, vector<int>& visited, vector<vector<int>>& a, int n)
{
    //cout << " current " << u << endl;
    //
    visited[u] = 1;
    ans.push_back(u);
    if(ans.size() == n + 1) { return true;}
    //for(auto elem : ans) cout << elem << " ho "; cout << endl;
    for(auto child : a[u])
    {
        //cout << " u " << u << " child " << child << endl;
        if(visited[child] == 1) continue;
        if(dfs(child, ans, visited, a, n) == true) {return true;}
    }
    visited[u] = 0;
    //cout << u << " visited is false now " << endl;
    //cout << u << " is popped back now " << endl;
    ans.pop_back();
    //cout << "returning false from " << u << endl;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2);
    for(int i = 1; i < n; i++) a[i].push_back(i + 1);
    vector<int> visited(n + 2, 0);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == 0) a[i].push_back(n + 1);
        else a[n + 1].push_back(i);
    }
    bool f = false;
    //for(int i = 1; i <= n + 1; i++)
    {
        //cout << i << " ";
        //for(auto elem : a[i]) cout << elem << " "; cout << endl;
    }
    vector<int> ans;
    for(int i = 1; i <= n + 1; i++)
    {
        //cout << " my node " << i << endl;
        bool d = dfs(i, ans, visited, a, n);
        if(d == true) {f = true; break;}
    }
    if(f == true)
    {
        for(auto elem : ans) cout << elem << " "; cout << endl;
    }
    else cout << -1 << endl;
}

void solve2()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2);
    for(int i = 1; i < n; i++) a[i].push_back(i + 1);
    vector<int> visited(n + 2, 0);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == 0) a[i].push_back(n + 1);
        else a[n + 1].push_back(i);
    }
    int pos = n + 1;
    if (a[n + 1].size() > 0)pos = a[n + 1][0];

    for(int i = 1; i <= n + 1; i++)
    {
        if(i < pos) cout << i << " ";
        else if(i == pos) cout << n + 1 << " ";
        else cout << i - 1 << " ";
    }
    cout << endl;
}

void solve3()
{
    int n, pos;
    cin >> n;
    pos = n + 1;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            if(pos == n + 1) pos = i;
        }
    }
    for(int i = 1; i <= n + 1; i++)
    {
        if(i < pos) cout << i << " ";
        else if(i == pos) cout << n + 1 << " ";
        else cout << i - 1 << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve3();
}
