#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    pair<ll,ll> p1 = {a,x};
    pair<ll,ll> p2 = {b,y};
    bool one = false;
    if(x == 1 || y == 1)
    {
        if(x == 1 && a - 1 <= n)
        {

            ll rem = n - (a - 1);
            a = 1;
            ll maxIcantake = min(b-y , rem);
            b -= maxIcantake;
            one = true;
            cout << a * b * 1ll << endl; return;
        }
        else if(y == 1 && b - 1 <= n)
        {
            ll rem = n - (b - 1);
            b = 1;
            ll maxIcantake = min(a - x, rem);
            a -= maxIcantake;
            one = true;
            cout << a * b * 1ll << endl; return;
        }

    }
    if(one == false)
    {
        pair<ll,ll> mini, maxi;
        if(a < b)
        {
            mini = p1; maxi = p2;
        }
        else if(a > b)
        {
            mini = p2; maxi = p1;
        }
        else
        {
            if(x < y) {mini = p1; maxi = p2;}
            else if (x > y) {mini = p2; maxi = p1;}
            else {mini = p1; maxi = p2;}
        }
        ll maxIcantake = min(mini.first - mini.second, n);
        ll rem = n - maxIcantake + 0ll;
        ll max2Icantake = min(maxi.first - maxi.second, rem);


        ll maxIcantake2 = min(maxi.first - maxi.second, n);
        ll rem2 = n - maxIcantake2 + 0ll;
        ll max2Icantake2 = min(mini.first - mini.second, rem2);

        /*mini.first -= maxIcantake + 0ll;
        maxi.first -= max2Icantake + 0ll;
        a -= maxIcantake2;
        b -= max2Icantake2;*/
        ll c = mini.first - maxIcantake;
        ll d = maxi.first - max2Icantake;
        ll e = maxi.first - maxIcantake2;
        ll f = mini.first - max2Icantake2;

        cout << min(c*d*1ll , e*f*1ll) << endl; return;
    }
    //cout << a << " " << b << endl;

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
