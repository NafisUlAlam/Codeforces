#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;


void solve6()
{
    ll n, q;
    cin >> n >> q;
    vector<ll>a(n), lfqi(n, - 1), lfqv(n, 0);
    ll sum = 0, lsqi = -1, lsqv = 0;
    for(int i = 0; i < n; i++) {cin >> a[i]; lfqv[i] = a[i];sum += a[i];}
    //cout << "sum" << sum << endl;
    for(int i = 1; i <= q; i++)
    {
        ll type, in, val;
        cin >> type;
        if(type == 1)
        {
            ll diff;
            cin >> in >> val;
            in--;
            //cout << "lsqi " << lsqi <<" lfqi[in] "<<lfqi[in]<< endl;
            if (lsqi > lfqi[in]) diff = lsqv;

            else  diff = lfqv[in];
            //cout << "diff " << diff <<" lfqv[in] "<<lfqv[in]<< endl;
            lfqi[in] = i;
            lfqv[in] = val;
            sum += val;
            sum -= diff;
            cout << sum << endl;
        }
        else if(type == 2)
        {
            cin >> val;
            lsqi = i;
            lsqv = val;
            sum = n * 1ll * lsqv;
            cout << sum << endl;
        }
    }
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {solve6();}

}
