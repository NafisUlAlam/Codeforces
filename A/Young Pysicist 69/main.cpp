#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    int p = 3;
    cin >> n;
    unsigned int out[p] = {0};
    int arr[n][p];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < p; i++){
       for (int j = 0; j < n; j++){
            out[i] += arr[j][i];
        }
    }
    if (out[0] == 0 && out[1] == 0 && out[2] == 0) cout << "YES";
    else cout <<"NO";



}
