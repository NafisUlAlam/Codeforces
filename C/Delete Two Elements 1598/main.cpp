#include <bits/stdc++.h>

using namespace std;


void solve()
{
    int n;
    cin >> n;
    vector<double> myvec(n);
    map<double,double> mymap;
    long double mean = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> myvec[i];
        mean += myvec[i];
        mymap[myvec[i]]++;
    }
    mean /= (n * 1.0);

    long long result = 0;
    for(int i = 0; i < n; i++)
    {
        double current = myvec[i];
        double needed = (2.0 * mean) - current;


        if(current == needed)
        {
            result += (mymap[current] * 1ll * (mymap[current] - 1)) / 2;
        }
        else
        {
            result += mymap[current] * 1ll * mymap[needed];
        }
        mymap[current] = 0; mymap[needed] = 0;
    }
    cout << result << endl;



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
