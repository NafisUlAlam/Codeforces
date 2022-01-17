#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve()
{
    int n; ll sum;
    cin >> n >> sum;
    vector<int> myvec(n);
    for(int i = 0; i < n; i++) cin >> myvec[i];

    int l = 0, r = 0;
    ll cursum = 0;
    ll noofsegs = 0;
    ll lenofsegs = 0;

    for(r = 0; r < n; r++)
    {
        cursum += myvec[r];

        while(cursum > sum)
        {
            cursum -= myvec[l];
            l++;

        }
        noofsegs = (r - l + 1);
        lenofsegs += (noofsegs * (noofsegs + 1) * 1ll) / 2;

    }
    cout << lenofsegs << endl;

}

int main()
{
   int t = 1;
   while(t--) solve();
}
