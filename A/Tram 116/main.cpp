#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxnum = 0;
    int current = 0;
    while (n--){
        int exited, entered;
        cin >> exited >> entered;
        current += entered - exited;
        maxnum = max(maxnum, current);
    }
    cout << maxnum;
}
