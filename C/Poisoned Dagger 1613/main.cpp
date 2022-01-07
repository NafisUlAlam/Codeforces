#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;


ull n, h, sum, current;

vector<int> myvec;

void reset()
{
    sum = 0; current = 0;
}


bool check(ull x)
{
    reset();
    for (int i = 0; i < n; i++)
    {
        if(myvec[i] <= current)
        {
            ull tosub = current - myvec[i] + 1;
            current = myvec[i] + x - 1;
            sum += current - myvec[i] - tosub + 1;
        }
        else
        {
            current = myvec[i] + x - 1;
            sum += current - myvec[i] + 1;
        }
    }
    return (sum >= h);
}


bool check2(ull x)
{
    reset();
    for (int i = 0; i < n; i++)
    {
        ull tosub = 0;
        if(myvec[i] <= current)
        {
            tosub = current - myvec[i] + 1;
        }
        current = myvec[i] + x - 1;
        sum += current - myvec[i] - tosub + 1;

    }
    return (sum >= h);
}

int main()
{
    ull t;
    cin >> t;
    while(t--)
    {

        cin >> n >> h;
        myvec.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> myvec[i];
        }


        ull lo = 1; ull hi = h;


        while(hi - lo > 1)
        {
            ull mid = hi - ((hi - lo) / 2);
            if(check(mid) == true)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        if(check(lo) == true) cout << lo << endl;
        else cout << hi << endl;

//        ull k;
//        for(k = 1; k <= h ; k++)
//        {
//            //cout << " k : " << k << endl;
//            current = 0;
//            sum = 0;
//            for(int i = 0; i < n; i++)
//            {
//                if(myvec[i] <= current)
//                {
//                    int tosub = current - myvec[i] + 1;
//                    current = myvec[i] + k - 1;
//                    sum += current - myvec[i] - tosub + 1;
//                }
//                else
//                {
//                    current = myvec[i] + k - 1;
//                    sum += current - myvec[i] + 1;
//                }
//               // cout <<" elems : " << current ;
//
//            }
//            //cout << endl;
//            //cout <<"sum " << sum << endl;
//            if(sum >= h)
//            {
//                cout << k << endl ; break;
//            }
//        }
    }
}
