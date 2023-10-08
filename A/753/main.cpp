#include <bits/stdc++.h>

using namespace std;

void pre(vector<vector<int>>& a, vector<int>& maxis, int n)
{
    a[0][0] = 0;
    for(int coin = 1; coin <= n - 1; coin++)
    {
        for(int sum = coin; sum <= n - 1; sum++)
        {
            a[coin][sum] = maxis[sum - coin] + 1;
        }
        for(int i = 1; i <= n - 1; i++) maxis[i] = max(maxis[i], a[coin][i]);
    }

}

int main()
{
    int n = 1005;
    vector<vector<int>> a(n, vector<int>(n, INT_MIN));
    vector<int> maxis(n, INT_MIN), ans; maxis[0] = 0;
    pre(a, maxis, n);
    //solve();
    int sum;
    cin >> sum;
    while(sum > 0)
    {
        int curr = INT_MIN, coin;
        for(int i = 0; i <= 1000; i++)
        {
            if(curr < a[i][sum])
            {
                curr = a[i][sum];
                coin = i;
            }
        }
        ans.push_back(coin);
        sum -= coin;
    }
    cout << ans.size() << endl;
    for(auto e : ans) cout << e << " "; cout << endl;
}
