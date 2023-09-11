// Segment with Small Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    int n;
    ull s;
    ull sum = 0;
    cin >> n >> s;
    vector<int> myvec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> myvec[i];
    }

    int l = 0, res = 0;
    for (int r = 0; r < n; r++)
    {
        sum += myvec[r];
        while (sum > s)
        {
            sum -= myvec[l];
            l++;
        }
        res = max(res, r - l + 1);
    }

    cout << res << endl;
}

