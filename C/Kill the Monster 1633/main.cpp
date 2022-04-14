#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    bool win = false;
    for(ll def = 0; def <= k; def++)
    {

        ll hc1 = hc, dc1 = dc;
        ll att = (k - def) * w * 1ll;
        ll defe = def * a * 1ll;
        dc1 += att + 0ll;
        hc1 += defe + 0ll;
        //cout << hc1 << " " << dc1 << endl;
        //cout << hm << " " << dm << endl;
        ll cmoves = (hm + dc1 - 1) / dc1;
        ll mmoves = (hc1 + dm - 1) / dm;
        //cout <<"moves "<< cmoves << " " << mmoves << endl;
        if(cmoves <= mmoves)
        {
            //cout << def << endl;
            win = true; break;
        }
    }
    if (win) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
