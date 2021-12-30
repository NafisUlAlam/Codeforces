// Segment with Big Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;


int main()
{
    int n; ull s;
    cin >> n >> s;
    vector<int> myvec(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> myvec[i];
    }
    ull sum = 0;
    int res = INT32_MAX;
    int r = 0, l = 0;
    for (r = 0; r < n; r++)
    {
        sum += myvec[r];
        
        
        while (sum - myvec[l] >= s)
        {
            sum -= myvec[l];
            l++;
        }

        if(sum >= s)res = min(res, r - l + 1);

        
    }
    res = (res == INT32_MAX) ? -1 : res;
    cout << res << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
