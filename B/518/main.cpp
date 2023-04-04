#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
   string s, t;
   cin >> s >> t;
   int n1 = s.size(), n2 = t.size();
   vector<int> caps(26, 0), small(26, 0), caps2(26, 0), small2(26, 0);
   ll cnt1 = 0, cnt2 = 0;
   for(int i = 0; i < n1; i++)
   {
      if(isupper(s[i])) caps[s[i] - 'A']++;
      else small[s[i] - 'a']++;
   }
   for(int i = 0; i < n2; i++)
   {
      if(isupper(t[i])) caps2[t[i] - 'A']++;
      else small2[t[i] - 'a']++;
   }
   for(int i = 0; i < 26; i++)
   {
      int mini = min(small[i], small2[i]);
      cnt1 += mini;
      small[i] -= mini;
      small2[i] -= mini;
      mini = min(caps[i], caps2[i]);
      cnt1 += mini;
      caps[i] -= mini;
      caps2[i] -= mini;
      small[i] += caps[i];
      small2[i] += caps2[i];
      cnt2 += min(small[i], small2[i]);
   }
   cout << cnt1 << " " << cnt2 << endl;
}

int main()
{
    solve();
}