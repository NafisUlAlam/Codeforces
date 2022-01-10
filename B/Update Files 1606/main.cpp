#include<bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    ll n,k;
    cin >> n>> k;
    /*//if(n == 1) {cout << 0 << endl; return;}
    ll firsthours = (log2(k)) + 1 ;
    //cout << firsthours << endl;
    ll numofcompsforfirsthour = pow(2,firsthours);
    //cout << numofcompsforfirsthour << endl;
    ll restofcomps = max(0ll, n - numofcompsforfirsthour);
    //cout << restofcomps << endl;
    ll secondhours = (restofcomps + k - 1) / k;
    //cout << secondhours << endl;
    cout << firsthours + secondhours << endl;*/
    ll start = 1;
    ll hour = 0;
    while( start < k)
    {
        start *= 2;
        hour++;
    }
    ll rem = n - start;
    if (rem <= 0) {cout << hour << endl; return;}
    ll additionalhour = rem / k;
    if(rem % k != 0) additionalhour++;
    cout << hour + additionalhour + 0ll << endl;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

}
