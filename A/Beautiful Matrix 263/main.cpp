#include <iostream>

using namespace std;

int main()
{
    int row, col;
    int arr[6][6];
    for (int i = 1; i < 6; i++){
        for (int j = 1; j < 6; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 1){
                row = i;
                col = j;
            }
        }
    }
    cout << abs(row - 3) + abs(col - 3);
}
