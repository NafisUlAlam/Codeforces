#include <bits/stdc++.h>

using namespace std;

int main()
{
    int wtlmk, wtbob;
    cin >> wtlmk >> wtbob;
    int year = 0;
    while (wtlmk <= wtbob){
        wtlmk *= 3;
        wtbob *= 2;
        year += 1;
    }
    cout << year ;
}
