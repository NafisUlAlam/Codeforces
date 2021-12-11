#include <bits/stdc++.h>

using namespace std;


bool isSorted(int arr[], int len)
{
    for(int i = 1; i <= len - 2; i++)
    {
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}

void findstartend(int arr[], int len, int& start, int& finish)
{
    bool foundstart = false;
    bool foundfinish = false;
    for (int i = 2; i < len; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            if(foundstart == false)
            {
                foundstart = true;
                start = i - 1;
                finish = i;
            }
            else
            {
                finish = i;
            }
        }
        else
        {
             if(foundstart == true) break;
             else continue;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arrsize = n + 1;
    int arr[arrsize];
    arr[0] = 0;
    for (int i = 1; i < arrsize; i++)
    {
        cin >> arr[i];
    }
    int start = 0;
    int finish = 0;
    findstartend(arr, arrsize, start,finish);
    reverse(arr + start, arr + finish + 1);
    if(isSorted(arr, arrsize) )
    {
        cout << "yes" << endl;
        if(start == 0) cout << 1 << " " << 1;
        else cout << start << " " << finish;
    }
    else
    {
        cout << "no" << endl;
    }

}
