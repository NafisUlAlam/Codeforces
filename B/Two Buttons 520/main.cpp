#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

//ull bfs(ull start, ull dest){
//    ull myans = 0;
//    queue<pair<ull,ull>> myque;
//    myque.push({start,0});
//    while(true){
//        ull current = myque.front().first;
//        ull timer = myque.front().second;
//        if (current == dest){
//            myans = timer; break;
//        }
//        myque.pop();
//        myque.push({current - 1, timer + 1});
//        if (current < dest)myque.push({current * 2, timer + 1});
//    }
//
//    return myans;
//}



int main()
{
    ull start, dest, myans;
    cin >> start >> dest;
    myans = 0;

    while (start < dest){
        if(dest % 2 == 1){
            dest += 1; myans += 1;
        }
        dest /= 2;
        myans += 1;
    }


    if(start >= dest) myans += (start - dest);
    cout << myans;
}
