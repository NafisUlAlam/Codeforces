#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >>t ;
    while(t--)
    {
        int n;
        cin >> n;
        int j = 3;
        for (int i = 1; i <= n; i++)
        {
            cout << j << " ";
            j += 1;

        }
        cout << endl;
    }
}
