#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main()
{
    ull n;
    cin >> n;
    ull arr[n];
    unordered_map<ull,ull> ump;
    for (int i = 0 ; i < n; i++)
    {
        cin >> arr[i];
        ump[arr[i]] += 1;
    }

    sort(arr, arr+n);
    ull myans = arr[n-1] - arr[0];
    ull myways;
    if(n == 2) myways = 1;
    else if (arr[0] == arr[n-1]) myways = (ump[arr[0]] * (ump[arr[0]] - 1) )/ 2 ;
    else myways = ump[arr[0]] * (ump[arr[n-1]] ) ;
    cout << myans <<" "<< myways;
}
