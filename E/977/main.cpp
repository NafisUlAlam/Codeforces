#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findParent(int node, vector<int>& parent)
{
    if(parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
//    int val = findParent(parent[node], parent);
//    parent[node] = val;
//    return val;
}

void join(int u, int v,vector<int>& parent, vector<int>& ranks, vector<int>& cycle)
{
    //cout << "joining " << u << " " << v << endl;
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);
    if(parentU == parentV)
    {
        cycle[parentU]++;
        return;
    }
    if(ranks[parentU] < ranks[parentV]) swap(parentU, parentV);
    else if(ranks[parentV] == ranks[parentU]) ranks[parentU]++;
    parent[parentV] = parentU;
}

void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> parent(n), ranks(n, 0), deg(n, 0), cycle(n, 0);
    for(int i = 0; i < n; i++) parent[i] = i;
    for(int x, y, i = 0; i < m; i++)
    {
        cin >> x >> y;
        x -= 1; y -= 1;
        deg[x]++; deg[y]++;
        if(x > y) swap(x, y);
        join(x, y, parent, ranks, cycle);
    }
    //for(auto e : parent) cout << e + 1 << " "; cout << endl;
    //for(auto e : ranks) cout << e << " "; cout << endl;
    //for(auto e : cycle) cout << e << " "; cout << endl;
    for(int i = 0; i < n; i++)
    {
        int p = findParent(i, parent);
        int d = deg[i];
        if(d != 2) cycle[p] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(parent[i] == i && cycle[i] == 1) ans++;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}

//7 7
//1 2
//2 3
//3 1
//4 5
//5 6
//6 7
//7 4
