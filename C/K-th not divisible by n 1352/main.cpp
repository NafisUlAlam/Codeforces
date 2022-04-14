#include<bits/stdc++.h>
#define ll long long
using namespace std;



void solve()
{
    int n, k;
    cin >> n >> k;
    int howmuch = n - 1;
    int toadd = (k - 1) / (n - 1);
    cout << k + toadd + 0ll << endl;
}
int main()
{
   int t;
   cin >> t;
   while(t--) solve();
}
