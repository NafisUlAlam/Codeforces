#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> myvec(n);
        for(int i = 0; i < n; i++) cin >> myvec[i];

        vector<long long> mygcd(myvec.begin(), myvec.begin() + 2);
        for(int i = 0; i < n; i++)
        {
            mygcd[i % 2] = __gcd(mygcd[i % 2], myvec[i]);
        }

        vector<bool> good(2,true);


        for(int i = 0; i < n; i++)
        {
            good[i % 2] = good[i % 2] && (myvec[i] % mygcd[(i % 2) ^ 1] > 0);
        }

        long long ans = 0;

        for(int i = 0; i < 2; i++)
        {
            if(good[i] == true) ans = mygcd[1 - i];
        }
        cout << ans << endl;

    }
}
