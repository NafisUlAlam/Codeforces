#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    long long ans = a;
    while(a >= b)
    {
        //cout << a << endl;
        int rem = a % b;
        a = a / b;

        ans += a;
        a += rem;
        //cout << a << endl;
    }
    cout << ans << endl;


}
