#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll maxHeight(int ind, int prev, vector<int>& a, vector<int>& b)
{
    if(ind > n) return 0ll;
    cout << ind << " " << a[ind] << " " << b[ind] << endl;
    ll choose1 = 0ll;
    ll choose2 = 0ll;
    ll notchoose = 0ll;
    if(prev == 0)
    {
        choose1 = a[ind] + maxHeight(ind + 1, 1, a, b);
        choose2 = b[ind] + maxHeight(ind + 1, 2, a, b);
        notchoose = 0 + maxHeight(ind + 1, 0, a, b);
    }
    else if(prev == 1)
    {
        choose2 = b[ind] + maxHeight(ind + 1, 2, a, b);
        notchoose = 0 + maxHeight(ind + 1, 0, a, b);
    }
    else
    {
        choose1 = a[ind] + maxHeight(ind + 1, 1, a, b);
        notchoose = 0 + maxHeight(ind + 1, 0, a, b);
    }
    //cout << "hi" << endl;
    return max(choose1, max(choose2, notchoose));
}


void solve1195C_Recursive()
{
   cin >> n;
   vector<int> a(n + 1, 0), b(n + 1, 0);
   for(int i = 1; i <= n; i++) cin >> a[i];
   for(int i = 1; i <= n; i++) cin >> b[i];
   cout << maxHeight(1, 0, a, b) << endl;
}

void solve1195C_DP()
{
   cin >> n;
   vector<int> a(n + 1, 0), b(n + 1, 0);
   for(int i = 1; i <= n; i++) cin >> a[i];
   for(int i = 1; i <= n; i++) cin >> b[i];
   vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));

   for(int i = 1; i <= n; i++)
   {
       for(int j = 0; j < 3; j++)
       {
           if(j == 0) dp[i][j] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
           else if (j == 1) dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + a[i];
           else if(j == 2) dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
       }
   }

   cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve1195C_Recursive();
    int t = 1;
    //cin >> t;
    while(t--) solve1195C_DP();
}
