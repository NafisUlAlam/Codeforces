#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve1744D()
{
   ll n;
   cin >> n;
   vector<ll> a(n + 1), b;
   ll need = n;
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      int cnt = 0;
      while(a[i] % 2 == 0)
      {
          cnt++;
          a[i] /= 2;
      }
      need -= cnt;

      int j = i;
      cnt = 0;
      while(j % 2 == 0)
      {
         cnt++;
         j /= 2;
      }
      if(cnt > 0) b.push_back(cnt);
   }

   sort(b.begin(), b.end(), greater<ll> ());
   ll sum = 0;
   for(int i = 0; i < b.size(); i++) sum += b[i];
   //cout << sum << " sum need" << need << endl;
   if(sum < need)
   {
      cout << "-1" << endl;
      return;
   }
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      if(need > 0)
      {
         need -= b[i];
         ans++;
      }
   }
   cout <<ans << endl;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   cin >> t;
   while(t--)
   {
      solve1744D();
   }
}
