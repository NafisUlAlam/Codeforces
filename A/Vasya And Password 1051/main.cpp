#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char small = 'a';
        char big = 'A';
        char num = '0';
        string input;
        cin >> input;
        int smallcount = 0, bigcount = 0, numcount = 0;

        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] >= 'a' && input[i] <= 'z') smallcount++;
            if(input[i] >= 'A' && input[i] <= 'Z') bigcount++;
            if(input[i] >= '0'  && input[i] <= '9') numcount++;

        }
        string output;
        if(smallcount == 0) output += small;
        if(bigcount == 0) output += big;
        if(numcount == 0) output += num;


        if(output == "") cout << input << endl;
        else
        {
            int whatsmax = max(smallcount, max(bigcount,numcount));
            for(int i = 0 ; i < input.size(); i++)
            {
                if(input[i] >= '0' && input[i] <= '9' && whatsmax == numcount)
                {
                    string firstinput = input.substr(0,i);
                    string secondinput = input.substr(i+ output.size());
                    output = firstinput + output + secondinput;
                    break;
                }
                else if(input[i] >= 'a' && input[i] <= 'z' && whatsmax == smallcount)
                {
                    string firstinput = input.substr(0,i);
                    string secondinput = input.substr(i+ output.size());
                    output = firstinput + output + secondinput;
                    break;
                }
                else if(input[i] >= 'A' && input[i] <= 'Z' && whatsmax == bigcount)
                {
                    string firstinput = input.substr(0,i);
                    string secondinput = input.substr(i+ output.size());
                    output = firstinput + output + secondinput;
                    break;
                }
            }
            cout << output << endl;
        }

    }
}
