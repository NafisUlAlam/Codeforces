#include <bits/stdc++.h>

using namespace std;

void solve550C()
{
   string s;
   cin >> s;
   int n = s.size();
   vector<vector<bool>> a(n, vector<bool>(8, false));
   vector<vector<pair<int, bool>>> ans(n, vector<pair<int, bool>>(8, make_pair(-1, false)));
   for(int i = 0; i < n; i++)
   {
      int curr = (s[i] - '0') % 8;
      a[i][curr] = true;
      ans[i][curr].second = true;
   }

   for(int i = 0; i + 1 < n; i++)
   {
      int curr = s[i] - '0';
      for(int j = 0; j < 8; j++)
      {
         if(a[i][j] == true)
         {
            if(a[i + 1][j] == false)
            {
               a[i + 1][j] = true;
               ans[i + 1][j].first = j;
            }
            int next = s[i + 1] - '0';
            if(a[i + 1][(j * 10 + next) % 8] == false)
            {
               a[i + 1][(j * 10 + next) % 8] = true;
               ans[i + 1][(j * 10 + next) % 8].first = j;
               ans[i + 1][(j * 10 + next) % 8].second = true;
            }
         }
      }
   }
   string out;
   for(int i = 0; i < n; i++)
   {
      if(a[i][0] == true)
      {
         int j = i, k = 0;
         while(j >= 0 && k >= 0 && k <= 7)
         {
            if(ans[j][k].second == true) out.push_back(s[j]);
            k = ans[j][k].first;
            j--;
         }
         break;
      }
   }
   reverse(out.begin(), out.end());
   if(out.size() > 0) cout << "YES" << endl << out << endl;
   else cout << "NO" << endl;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   //cin >> t;
   while(t--)
   {
      solve550C();
      //solve1881DfrmPC;
      //disjointsetsEDU;
      //solve1654CFromPC;
   }
}
