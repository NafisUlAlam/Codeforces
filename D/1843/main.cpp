#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll get(int ind, vector<vector<ll>>& a, vector<ll>& child, vector<bool>& visited)
{
    if(a[ind].size() == 1 && visited[a[ind].back()] == true) return child[ind] = 1;
    visited[ind] = true;
    for(auto e : a[ind])
    {
        if(visited[e] == true) continue;
        child[ind] += get(e, a, child, visited);
    }
    return child[ind];
}

void solve()
{
    ll n, q, x, y;
    cin >> n;
    vector<vector<ll>> a(n + 1);
    vector<ll> child(n + 1, 0);
    vector<bool> visited(n + 1, false);
    for(ll i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    get(1, a, child, visited);
    //for(int i = 1; i <= n; i++) cout << child[i] << " "; cout << endl;
    cin >> q;
    while(q--)
    {
        cin >> x >> y;
        cout <<child[x] * 1ll * child[y] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
