#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solveUsingTwoPointer()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto& e: a) cin >> e;

    int maxi = INT_MIN;

    int left = 0, right = 0, sum = 0;
    for(; right < n; right++)
    {
        sum += a[right];
        while(sum > s)
        {
            sum -= a[left];
            left++;
        }
        if(sum == s)
        {
            maxi = max(maxi, right - left + 1);
        }
    }

    if(maxi == INT_MIN) cout << -1 << endl;
    else cout << n - maxi << endl;

}
void solve1692E()
{
   int n, s;
   cin >> n >> s;
   vector<int> a;
   int sum = 0, mov = 0;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x == 1) a.push_back(i);
      sum += x;
   }
   //cout << "sum : " << sum << " s :"<< s << endl;
   //for(auto elem : a) cout << elem << " "; cout << endl;
   if(sum < s) cout << -1 << endl;
   else if (sum == s) cout << 0 << endl;
   else
   {
      int left = 0, right = n - 1;
      int p = a.size();
      int i = 0, j = p - 1;
      int cleft = a[i], cright = a[j];
      while(sum > s)
      {
         if(left > right) break;

         int lmov = cleft - left + 1;
         int rmov = right - cright + 1;

         //cout << "right : "<< right << " cright :" << cright << endl;

         if(lmov < rmov)
         {
            mov += lmov;
            left = cleft + 1;
            cleft = a[++i];
         }
         else
         {
            mov += rmov;
            right = cright - 1;
            cright = a[--j];
         }
         sum--;
      }
      cout << mov << endl;
   }
}


int query(int l, int r, vector<int>& pref)
{
    return pref[r] - (l > 0? pref[l - 1] : 0);
}

void solveusingBinarySearch()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n), pref(n, 0);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        pref[i] = (i > 0? pref[i - 1] + a[i] : a[i]);
    }

    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int l = i, r = n - 1, pos = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(query(i, mid, pref) <= s)
            {
                pos = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if(pos == -1 || query(i, pos, pref) != s) continue;
        ans = min(ans, n - (pos - i + 1));
    }

    cout << (ans == INT_MAX? -1 : ans) << endl;

}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solveusingBinarySearch();
}
