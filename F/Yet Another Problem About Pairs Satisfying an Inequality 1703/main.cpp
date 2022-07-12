#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solveUsingBruteForce()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;

    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= i) continue;
        for(int j = i + 1; j <= n; j++)
        {
            if(a[j] < j && i < a[j]) ans++;
        }
    }
    cout << ans << endl;
}

void solveUsingBinarySeach()
{
   int n;
   cin >> n;
   vector<int> a(n + 1);
   vector<pair<int, int>> b;
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      if(a[i] < i)
      {
         b.push_back({a[i], i});
      }
   }

   sort(b.begin(), b.end());

   //for(auto elem : b) cout <<"(" << elem.first << " " << elem.second <<")"; cout << endl;

   int sz = b.size();
   ll ans = 0;
   for(int i = 0; i < sz; i++)
   {
      int lo = i + 1, hi = sz - 1, x = -1;

      while(lo <= hi)
      {
         int mid = (lo + hi) / 2;
         if(b[i].second >= b[mid].first || b[i].second >= b[mid].second)
         {
            lo = mid + 1;
         }
         else
         {
            x = mid;
            hi = mid - 1;
            //if(i == 5)cout << x << endl;
         }
      }
      if(x != -1)
      {
         //cout << sz - x << endl;
         ans += sz - x;
      }
   }
   cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        //solveUsingBruteForce();
        solveUsingBinarySeach();
    }
}
