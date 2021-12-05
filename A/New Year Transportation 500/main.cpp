#include <iostream>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    int arr[n];
    for (int i = 1; i < n; i++){
        cin >> arr[i];
    }
    int start = 1;
    int ending = t;
    while(start < ending){
        start += arr[start];
    }
    if(start == ending) cout << "YES";
    else cout << "NO";
}
