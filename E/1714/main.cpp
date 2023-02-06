#include <bits/stdc++.h>

using namespace std;

vector<int> b = {2, 4, 8, 6};
vector<vector<bool>> mp(10, vector<bool>(21, false));
void pre()
{
    for(int i = 0; i < 4; i++)
   {
      int key = b[i];
      int sum = 0;
      int k = i;
      for(int j = 1; j <= 3; j++)
      {
         sum += b[k];
         mp[key][sum] = true;
         k = (k + 1) % 4;
      }
   }
//   for(auto elem : mp)
//   {
//       cout <<" row ";
//       for(auto e : elem) cout << e << " "; cout << endl;
//   }
}
void solve1714E()
{
   int n;
   cin >> n;
   vector<int> a(n);
   /*for(auto elem : mp)
   {
      cout << elem.first << " ";
      for(auto e : elem.second) cout << e << " "; cout << endl;
   }*/
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] % 2 == 1) a[i] += a[i] % 10;
      while(a[i] != 0 && a[i] < 10) a[i] += a[i] % 10;
   }
   bool f = true;
   sort(a.begin(), a.end());
   for(int i = 0; i + 1 < n; i++)
   {
      if(a[i] == a[i + 1]) continue;
      int diff = a[i + 1] - a[i];
      int start = a[i] % 10;
      if(start == 0)
      {
         f = false;
         break;
      }
      diff %= 20;
      if(diff == 0) continue;
      if(mp[start][diff] == false)
      {
         f = false;
         break;
      }
   }
   if(f == true) cout << "YES" << endl;
   else cout << "NO" << endl;

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre();
    int t;
    cin >> t;
    while(t--) solve1714E();
}
