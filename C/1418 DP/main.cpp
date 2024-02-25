#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & e : a) cin >> e;
    vector<vector<int>> dp(n, vector<int>(2, 1e9));
    dp[0][0] = a[0];
    if(n > 1)
    {
        dp[1][0] = a[0] + a[1];
        dp[1][1] = a[0];
        for(int i = 2; i < n; i++)
        {
            dp[i][0] = min(dp[i][0], dp[i - 2][1] + a[i - 1] + a[i]);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i]);
            dp[i][1] = min(dp[i][1], min(dp[i - 1][0], dp[i - 2][0]));
        }
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
