#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;


int main()
{
    ull n; ull c;
    cin >> n >> c;
    vector<ull> myvec(n);
    ull sum = 0;
    for(ull i = 0; i < n; i++)
    {
        cin >> myvec[i];
        sum += myvec[i];
    }

    if(sum == c)
    {
        cout << 1 << " " << myvec.size();
    }

    else if(c > sum)
    {
        ull div = c / sum;
        ull rem = c % sum;
        ull mysum = 0;
        int r = 0;
        while(mysum < rem)
        {
            mysum += myvec[r];
            r++;
        }
        ull leftans = ( div * myvec.size() ) + r;
        cout << 1 << " " << leftans;
    }
    else
    {
        ull l = 0;
        ull myleftans = 0;
        ull lcounter = 0;
        ull rcounter = 0;
        int rotation = 0;
        ull currsum = 0;
        ull res = ULLONG_MAX;
        for(int r = 0; r < n; r = (r + 1) % n)
        {
            bool flag = false;
            if(rotation == 2  || res <= 2) break;

            currsum += myvec[r];
            while(currsum  >= c )
            {
                currsum -= myvec[l];
                l = (l + 1) % n;
                lcounter++;
                flag = true;
            }
            if(flag)
            {
                if(res > (rcounter - lcounter + 2))
                {
                    res = rcounter - lcounter + 2;
                    myleftans = (l  + n  - 1)  % n;
                }
            }
            if(r == (n - 1)) rotation++;
            rcounter++;
        }
        cout << myleftans + 1 << " " << res;
    }


}
