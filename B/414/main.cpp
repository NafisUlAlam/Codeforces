#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> dp(2005, vector<ll> (2005, -1));
ll mod = 1e9 + 7;
ll f(int n, int i, int k)
{
    if(k <= 0) return 1ll;
    if(dp[i][k] != -1) return dp[i][k];

    ll ans = 0;
    for(int j = 1; j <= n; j++)
    {
        if(j % i == 0)
        {
            ans = (ans % mod) +  (f(n, j, k - 1) % mod);
        }
    }
    return dp[i][k] = ans;
}

ll betterf(int n, int i, int k)
{
    if(k <= 0) return 1ll;
    if(dp[i][k] != -1) return dp[i][k];

    ll ans = 0;
    for(int j = i; j <= n; j += i)
    {
        ans += betterf(n, j, k - 1) % mod;
    }
    return dp[i][k] = ans;
}

void solveRecursive()
{
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = (ans % mod) +  (betterf(n, i, k - 1) % mod);
    }
    cout << ans << endl;
}

void solveDP()
{
   ll n, k;
   cin >> n >> k;
   if(k == 1)
   {
      cout << n << endl;
      return;
   }
   ll mod = 1e9 + 7;
   vector<vector<ll>> a(k + 1, vector<ll> (n + 1, 0ll));

   ll sum1 = 0;
   for(int col = 1; col <= n; col++)
   {
      a[2][col] = n / col;
      sum1 = (sum1 + a[2][col]) % mod;
   }
   for(int row = 3; row <= k; row++)
   {
      for(int col = 1; col <= n; col++)
      {
         if(col == 1)
         {
            a[row][col] = sum1;
            continue;
         }
         ll sum = 0;
         for(int c = col; c <= n; c += col)
         {
            sum = (sum + a[row - 1][c]) % mod;
         }
         a[row][col] = sum;
         sum1 = (sum + sum1) % mod;
      }
   }

   cout << sum1 << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   //cin >> t;
   while(t--)
   {
      //solveDP();
      solveRecursive();
   }
}
