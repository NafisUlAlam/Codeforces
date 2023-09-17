#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dfs(int node, int parent, vector<vector<pair<int, int>>>& a, ll& ans)
{
    vector<int> temp;
    bool flag = false;
    for(auto child : a[node])
    {
        int newchild = child.first;
        int edge = child.second;
        if(newchild == parent) continue;
        flag = true;
        ll p = dfs(newchild, node, a, ans);
        temp.push_back(p + edge);
    }

    if(flag == false) return 0;
    ans += abs(temp[0] - temp[1]);
    return max(temp[0], temp[1]);

}

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a( 1<<(n+1) );
    for(int w, i = 1; i <= (1<<(n + 1)) -2; i++)
    {
        cin >> w;
        int top = (i + 1) / 2;
        int bot = i + 1;
        a[top].push_back(make_pair(bot, w));
        a[bot].push_back(make_pair(top, w));
    }
    //for(auto e : a)
    {
        //for(auto e2 : e) cout << "( node " << e2.first << " weight " << e2.second << ")"; cout << endl;
    }
    ll ans = 0;
    dfs(1, -1, a, ans);
    cout << ans << endl;
}

int main()
{
    solve();
}
