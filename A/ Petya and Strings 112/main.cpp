#include <iostream>

using namespace std;

int main()
{
   string s1, s2;
   cin >> s1 >> s2;
   bool flag = false;
   for (int i = 0; i < s1.size(); i++){
        char f1 = toupper(s1[i]);
        char f2 = toupper(s2[i]);
        if(f1 == f2) continue;
        else{
            flag = true;
            if(f1 < f2){
                cout << -1;
                break;
            }
            else {
                cout << 1;
                break;
            }
        }
   }
   if (!flag) cout << 0;
}
