#include <bits/stdc++.h>

using namespace std;

bool check(int start, int finish, vector<int>& a)
{
    bool ans = true;
    vector<bool> flags(2e5 + 100, false);
    //for (auto e : flags) cout << e << " "; cout << endl;
    for(int i = 1; i <= finish; i++) flags[a[i]] = true;
    //for (auto e : flags) cout << e << " "; cout << endl;
    for(int i = 1; i <= finish; i++) ans &= flags[i];
    flags.assign(2e5 + 100, false);
    //for (auto e : flags) cout << e << " "; cout << endl;
    for(int i = finish + 1; i < (int)a.size(); i++) flags[a[i]] = true;
    //for (auto e : flags) cout << e << " "; cout << endl;
    for(int i = 1; i <= a.size() - finish - 1; i++) ans &= flags[i];
    return ans;
}


void solve()
{
    int n, maxi = INT_MIN;
    cin >> n;
    vector<int> a(n + 1);
    set<pair<int, int>> ans;
    for(int i = 1; i <= n; i++) {cin >> a[i]; maxi = max(a[i], maxi);}
    if(check(1, maxi, a))ans.insert(make_pair(maxi, n - maxi));
    if(check(1, n - maxi, a))ans.insert(make_pair(n - maxi, maxi));
    cout << ans.size() << endl;
    for(auto e : ans) cout << e.first << " " << e.second << endl;
}


int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
