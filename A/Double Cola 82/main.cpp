#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long start = 1;
    long long prev = start;
    long long mult = 5;
    int ans = 0;
    for(int i = 1; i <= 5; i++)
    {
        start = i;
        mult = start + 4;
        long long counter = 0;

        while(start <= n)
        {
            prev = start;
            start += mult + 0ll;
            mult *= 2ll;
            counter++;

        }
        long long mypower = pow(2, counter - 1);
        if(prev <= n && (prev + mypower - 1ll) >= n)
        {
            ans = i; break;
        }
    }

    if(ans == 1) cout << "Sheldon"<< endl;
    else if(ans == 2) cout << "Leonard"<< endl;
    else if(ans == 3) cout << "Penny" << endl;
    else if(ans == 4) cout << "Rajesh" << endl;
    else cout << "Howard" << endl;
}
