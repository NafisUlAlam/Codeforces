#include <bits/stdc++.h>

using namespace std;

vector<int> get(int u, vector<int>&a, vector<int>& mini, vector<int>& maxi, vector<int>& sizes, vector<int>& ranks)
{
    //cout << u << endl;
    vector<int> v;
    if(u == a[u])
    {
        v.push_back(u); v.push_back(mini[u]); v.push_back(maxi[u]); v.push_back(sizes[u]);
        return v;
    }
    v = get(a[u], a, mini, maxi, sizes, ranks);
    a[u] = v[0];
    mini[u] = v[1];
    maxi[u] = v[2];
    sizes[u] = v[3];
    return v;
}

void join(int u, int v, vector<int>& a, vector<int>& mini, vector<int>& maxi, vector<int>& sizes, vector<int>& ranks)
{
    vector<int> f = get(u, a, mini, maxi, sizes, ranks);
    vector<int> s = get(v, a, mini, maxi, sizes, ranks);
    u = f[0], v = s[0];
    if(u == v) return;
    if(ranks[u] < ranks[v]) {swap(u, v); swap(f, s);}
    else if(ranks[u] == ranks[v]) ranks[u]++;
    int fmini = f[1], smini = s[1], fmaxi = f[2], smaxi = s[2], fsize = f[3], ssize = s[3];
    a[v] = u;
    mini[u] = min(fmini, smini);
    maxi[u] = max(fmaxi, smaxi);
    sizes[u] += sizes[v];

}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), maxi(n + 1), mini(n + 1), sizes(n + 1, 1), ranks(n + 1, 1);
    for(int i = 0; i <= n; i++)
    {
        a[i] = i;
        maxi[i] = i;
        mini[i] = i;
    }

    for(int i = 1, u, v; i <= m; i++)
    {
        string s;
        cin >> s;
        if(s == "union")
        {
            cin >> u >> v;
            join(u, v, a, mini, maxi, sizes, ranks);
            //for(auto e : a) cout << e << " "; cout << endl;
            //for(auto e : mini) cout << e << " "; cout << endl;
            //for(auto e : maxi) cout << e << " "; cout << endl;
            //for(auto e : sizes) cout << e << " "; cout << endl;
        }
        else
        {
            cin >> u;
            vector<int> f = get(u, a, mini, maxi, sizes, ranks);
            for(int j = 1; j <= 3; j++) cout << f[j] << " "; cout << endl;
        }
    }
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
