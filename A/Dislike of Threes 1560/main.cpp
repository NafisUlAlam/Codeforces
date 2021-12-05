#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>v(1001,0);
    int current = 1;
    for (int i = 1; i <= 1000;){
        if(current % 3 == 0 || current % 10 == 3){
            current += 1;
        }
        else{
            v[i] = current;
            i += 1;
            current += 1;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        cout << v[k] << endl;
    }
}
