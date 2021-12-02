#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        int first = 0;
        int second = n - 1;
        for (int i = 0; i < (n / 2); i++){
            cout << arr[second] <<" "<< arr[first] << endl;
            second -= 1;
        }
    }
}
