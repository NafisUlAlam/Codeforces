#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> myvec(n);
    for(int i = 0; i < n; i++) cin >> myvec[i];


    int l = 0, r = 0;
    long long ways = 0;

    for(r = 0; r < n; r++)
    {
        if(r == l) continue;

        while(myvec[r] - myvec[l] > d)
        {

            l++;
            ways += n - r;
        }
    }
    cout << ways << endl;
}
