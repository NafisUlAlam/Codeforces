#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned int a,b,c,d;
    cin >> a >> b >> c >> d;
    unsigned int mx = max(a, max(b,max(c,d)));

    if (mx == a){
        b = mx - b;
        c = mx - c;
        d = mx - d;
        cout << b <<" "<< c <<" "<< d;
    }

    else if (mx == b){
        a = mx - a;
        c = mx - c;
        d = mx - d;
        cout << a <<" "<< c <<" "<< d;
    }

    else if (mx == c){
        b = mx - b;
        a = mx - a;
        d = mx - d;
      cout << b <<" "<< a <<" "<< d;
    }

    else if (mx == d){
        b = mx - b;
        c = mx - c;
        a = mx - a;
        cout << b <<" "<< c <<" "<< a;
    }




}
