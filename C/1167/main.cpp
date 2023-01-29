#include <bits/stdc++.h>

using namespace std;

void makeSet(vector<int>& parent, vector<int>& ranks)
{
    for(int i = 0; i < (int)parent.size(); i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findParent(int u, vector<int>& parent)
{
    if(parent[u] == u) return u;
    return parent[u] = findParent(parent[u], parent);
}

void join(int u, int v, vector<int>& parent, vector<int>& ranks)
{
    int uparent = findParent(u, parent);
    int vparent = findParent(v, parent);
    if(uparent == vparent) return;

    if(ranks[uparent] < ranks[vparent]) swap(uparent, vparent);
    parent[vparent] = uparent;
    if(ranks[uparent] == ranks[vparent]) ranks[uparent]++;
    //cout << " p ";for(auto elem : parent) cout << elem << " "; cout << endl;
    //cout << " r ";for(auto elem : ranks) cout << elem << " "; cout << endl;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1), ranks(n + 1), cnt(n + 1, 0);
    makeSet(parent, ranks);
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        vector<int> group(x);
        for(int i = 0; i < x; i++) cin >> group[i];
        for(int i = 0; i + 1 < x; i++)
        {
            join(group[i], group[i + 1], parent, ranks);
        }
    }
    for(int i = 1; i < n + 1; i++) findParent(i, parent);
    for(int i = 1; i < n + 1; i++) cnt[parent[i]]++;
    for(int i = 1; i < n + 1; i++) cout << cnt[parent[i]] << " "; cout << endl;
}



int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) solve();
//    int n = 8;
//    vector<int> parent(n + 1), ranks(n + 1), cnt(n + 1, 0);
//    makeSet(parent, ranks);
//    join(1, 2, parent, ranks);
//    join(3, 4, parent, ranks);
//    join(5, 6, parent, ranks);
//    join(7, 8, parent, ranks);
//    join(2, 4, parent, ranks);
//    join(6, 8, parent, ranks);
//    join(2, 8, parent, ranks);
//    cout << " p ";for(auto elem : parent) cout << elem << " "; cout << endl;

}
