#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> v(1000001,0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        v[arr[i]]++;
    }


    sort(arr,arr+n);
    int q;
    cin >> q;
    while(q--){
        int m;
        cin >> m;
        int lo = 0;
        int hi = n - 1;
        while(hi - lo > 1){
            long long mid = (hi + lo) / 2;
            if(arr[mid] <= m) lo = mid;
            else hi = mid - 1;
        }
        int myans = -1;
        if (arr[lo] <= m) myans = lo;
        if (arr[hi] <= m) myans = hi;
        cout << myans + 1 << endl;
    }

}
