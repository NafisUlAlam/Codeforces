#include <bits/stdc++.h>
using namespace std;

int main(){

    int police = 0;
    int untreated = 0;
    int n;
    cin >> n;
    while(n--){
        int number;
        cin >> number;
        if(number == -1){
            if(police == 0){
                untreated += 1;
            }
            else{
                police -= 1;
            }
        }
        else police += number;
    }
    cout << untreated;

}
