#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        bool dead = false;
        bool getwater = false;
        int ht = 1;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0;i <n;i++)
        {
            cin >> arr[i];
        }
        ht += arr[0];
        if (arr[0] == 1) getwater = true;

        for (int i = 1; i < n ; i++)
        {
            if(arr[i] == 0 && arr[i-1] == 0)
            {
                ht = -1;
                break;
            }
            if(arr[i] == 1)
            {
                if(getwater == false)
                {
                    getwater = true;
                    ht += 1;
                }
                else
                {
                    ht += 5;

                }
            }
            else getwater = false;

        }

        cout << ht << endl;

    }
}
