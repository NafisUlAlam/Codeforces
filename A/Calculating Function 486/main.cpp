#include<bits/stdc++.h>


using namespace std;



int main(){
    unsigned long long n;
    cin >> n;
    long long output = 0;
    if (n % 2 == 0) output = n / 2;
    else output = n / 2 - n;
    cout << output;



}
