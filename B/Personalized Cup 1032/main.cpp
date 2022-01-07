#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    int asteriks = 0;
    int astperrow = 0;
    int astrem = 0;
    int row = 1;
    int lenperrow = len;
    if(len > 20)
    {

        for (row = 1; row <= 5; row++)
        {
            lenperrow = (len + row - 1) / row;
            if(lenperrow <= 20)
            {
                asteriks =(row * lenperrow) - len;
                astperrow = asteriks / row;
                astrem = asteriks % row;
                break;
            }
        }

    }

    int k = 0;
    int col = min(lenperrow,len);
    cout << row << " " << col<< endl;
    for(int i = 1; i <= row; i++)
    {
        int count = 0;
        for(int j = 1; j <= astperrow; j++) cout << "*";
        if(astrem != 0)
        {
            cout << "*";
            astrem--;
            count++;

        }
        count += astperrow;
        for(int j = count + 1 ; j <= col; j++)
        {
            cout << s[k];
            k++;

        }
        cout << endl;
    }



}
