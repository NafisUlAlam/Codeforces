#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solveEduCourse2Lesson93PracticeE()
{
   int n, s;
   cin >> n >> s;
   vector<int> w(n), c(n);
   for(int i = 0; i < n; i++) cin >> w[i];
   for(int i = 0; i < n; i++) cin >> c[i];

   int l = 0, r = 0;
   ll ans = 0, weight = 0, cost = 0;
   for(r = 0; r < n; r++)
   {
      weight += w[r];
      if(weight <= s)
      {
         cost += c[r];
      }
      else
      {
         while(weight > s)
         {
            weight -= w[l];
            cost -= c[l];
            l++;
         }
         cost += c[r];
      }
      //cout << cost << endl;
      ans = max(ans, cost);
   }
   cout << ans << endl;
}

solveEduCourse2Lesson93PracticeE2()
{
   int n, s;
   cin >> n >> s;
   vector<int> w(n), c(n);
   for(int i = 0; i < n; i++) cin >> w[i];
   for(int i = 0; i < n; i++) cin >> c[i];

   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      ll weight = 0, cost = 0;
      for(int j = i; j < n; j++)
      {
         weight += w[j];
         cost += c[j];
         if(weight <= s)
         {
            ans = max(ans, cost);
         }
         else break;
      }
   }
   cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
    {
       //solve1692EFromPC();
       solveEduCourse2Lesson93PracticeE2();
    }
}
