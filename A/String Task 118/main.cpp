#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string output;
    int i = 0;
    for (; i < s.size(); i++){
        char f = tolower(s[i]);
        if(f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u' || f == 'y') {
            continue;
        }
        else{
            output += '.';
            output += f;
        }

    }
    cout << output << endl;
}
