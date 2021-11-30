#include <iostream>

using namespace std;

int main()
{
    bool flag = false;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            cout << "YES";
            flag = true;
            break;
        }
    }
    if (!flag) cout << "NO";
}
