#include <bits/stdc++.h>
using namespace std;

int get(vector<int>& a, int i, int n, int turn, vector<vector<int>>& dp)
{
    if(i >= n) return dp[i][turn] = 0;
    if(dp[i][turn] != 1e9) return dp[i][turn];
    if(turn == 0)
    {
        int one = 0, two = 0;
        one = get(a, i + 1, n, turn ^ 1, dp) + a[i];
        if(i + 1 < n) two = get(a, i + 2, n, turn ^1, dp) + a[i] + a[i + 1];
        else two = 1e9;
        return dp[i][turn] = min(one, two);
    }
    else
    {
        int one = 0, two = 0;
        one = get(a, i + 1, n, turn ^ 1, dp);
        two = get(a, i + 2, n, turn ^ 1, dp);
        return dp[i][turn] = min(one, two);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;
    vector<vector<int>> dp(n + 10, vector<int>(2, 1e9));
    cout << get(a, 0, n, 0, dp) << endl;;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
