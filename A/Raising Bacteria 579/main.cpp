#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    int x;
    cin >> x;
    while (x > 1){
        if(x & 1 && x != 1) i += 1;
        x /= 2;
    }
    cout << i;
}
