#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> parent(n + 1, make_pair(-1, 0)), child(n + 1, make_pair(0, 0));
    for(int i = 1, par, c; i <= n; i++)
    {
        cin >> par >> c;
        parent[i].first = par;
        parent[i].second = c;
        if(par != -1)
        {
            child[par].first += 1;
            child[par].second += c;
        }
    }
    //for(auto e : parent) cout << "( " << e.first << " " << e.second <<" ) "; cout << endl;
    //for(auto e : child) cout << "( " << e.first << " " << e.second <<" ) "; cout << endl;
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        if(parent[i].first == -1) continue;
        if(parent[i].second == 1)
        {
            if(child[i].first == child[i].second) ans.push_back(i);
        }
    }
    if(ans.size() == 0) cout << -1 << endl;
    else for(auto e : ans) cout << e << " "; cout << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
