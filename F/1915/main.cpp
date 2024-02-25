#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
using namespace std;
using namespace __gnu_pbds;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    ordered_set os;
    for(int x, y, i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) os.insert(a[i][1]);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += os.order_of_key(a[i][1]);
        os.erase(a[i][1]);
    }

    cout << ans << endl;


}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
