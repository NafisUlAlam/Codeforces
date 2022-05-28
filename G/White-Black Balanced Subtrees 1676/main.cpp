#include <bits/stdc++.h>

using namespace std;


vector<vector<int>>g;
vector<pair<int, int>> color;

void dfs(int v, int par = -1)
{
    //cout << "dfs";
    for(auto child : g[v])
    {
        //cout << child << " " << v << " "; cout << endl;
        if(child == par || child == v) continue;
        dfs(child, v);

        color[v].first += color[child].first;
        color[v].second += color[child].second;
    }
}


void solve6()
{
    int n;
    cin >> n;
    g.clear();
    g.assign(n + 1, {});
    color.clear();
    color.assign(n + 1, {0 , 0});
    for(int i = 2; i <= n ; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

//    for(auto elem : g)
//    {
//        for(auto e : elem) cout << e << " ";
//        cout << endl;
//    }

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'W') color[i + 1].first = 1;
        else color[i + 1].second = 1;
    }
    //for(auto e : color) cout << e.first << " " << e.second <<" "; cout << endl;


    dfs(1);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(color[i].first == color[i].second) cnt++;
    }
    cout << cnt << endl;
}



int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve6();

}
