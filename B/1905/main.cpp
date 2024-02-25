#include <bits/stdc++.h>

using namespace std;


void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int x, y, i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        --x; --y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int v = 0;
    for(auto e : a)
    {
        if(e.size() == 1) v++;
    }
    cout << (v + 1) / 2 << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
