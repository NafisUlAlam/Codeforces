#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string output = "hello";
    int i, j;
    i = j = 0;
    while(i < s.size() && j < output.size()){
        if(s[i] == output[j]){
            i++; j++;
        }
        else i++;
    }
    if (j == output.size()) cout << "YES";
    else cout << "NO";
}
