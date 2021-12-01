#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        unsigned long long mov = 0;
        int n;
        cin >> n;
        int orange[n];
        int candy[n];
        int minOrange =INT_MAX;
        int minCandy = INT_MAX;
        for (int i = 0; i < n; i++){
            cin >> orange[i];
            minOrange = min(minOrange,orange[i]);
        }
        for (int i = 0; i < n; i++){
            cin >> candy[i];
            minCandy = min(minCandy,candy[i]);
        }
        for (int i = 0; i < n; i++){
            int orangeDiff = orange[i] - minOrange;
            int candyDiff = candy[i] - minCandy;
            int minDiff = min(orangeDiff, candyDiff);
            candy[i] -= minDiff;
            orange[i] -= minDiff;
            mov += minDiff;
        }
            for (int i = 0; i < n; i++){
            int orangeDiff = orange[i] - minOrange;
            orange[i] -= orangeDiff;
            mov += orangeDiff;
        }
            for (int i = 0; i < n; i++){
            int candyDiff = candy[i] - minCandy;
            candy[i] -= candyDiff;
            orange[i] -= candyDiff;
            mov += candyDiff;
        }
        cout << mov << endl;
    }
}
