#include <bits/stdc++.h>

using namespace std;

void solve()
{
   string s;
   cin >> s;
   int n = s.size();
   int ans = 0;
   bool f = false;
   for(int i = n - 1; i >= 0; i--)
   {
      if(f == false)
      {
         if(s[i] == '0') ans++;
         else
         {
            if(i > 0)ans += 2;
            if(i > 0)f = true;
         }
      }
      else
      {
         if(s[i] == '1') ans++;
         else ans += 2;
      }
   }
   cout << ans << endl;
}

void solve2()
{
   string s;
   cin >> s;
   int n = s.size();
   int ans = 0;
   for(int i = n - 1; i >= 0; i--)
   {
      if(i == 0)
      {
         if(s[i] == '0') ans++;
         continue;
      }
      if(s[i] == '0')
      {
         ans++;
         continue;
      }
      else
      {
         int j = i;
         while(j >= 0 && s[j] == '1')
         {
            s[j] = '0';
            j--;
         }
         if(j >= 0) s[j] = '1';
         ans += 2;
      }
   }
   cout << ans << endl;
}

int main()
{
    solve();
}
