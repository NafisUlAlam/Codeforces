#include <bits/stdc++.h>

using namespace std;


int findMax(int a, int arr[], int level){
    if(a == 0) return level;
    if (a < 0) return -1;
    int mylevel = 0;
    for(int i = 0; i < 3; i++){
        int b = a - arr[i];
        mylevel = max(findMax(b, arr, level + 1), mylevel);
    }
    return mylevel;
}


int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int arr[3] ={a,b,c};
    sort(arr,arr+3);
    int arr2D[3][n+1];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n + 1; j ++)
        {
            arr2D[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = arr[i]; j < n + 1; j += arr[i])
        {
            arr2D[i][j] = arr2D[i][j-arr[i]] + 1;
        }
    }


    for (int row = 0; row < 3; row++){
        for(int j = arr[row]; j < n + 1; j +=arr[row]){

            for (int row2 = 0; row2 < 3; row2++){
                if(row == row2) continue;
                int counter = arr2D[row][j];
                int k = j + arr[row2];
                for (; k < n + 1; k += arr[row2] ){
                    arr2D[row2][k] = max(counter + 1, arr2D[row2][k]);
                    counter = arr2D[row2][k];
                }

            }
        }
    }

    int a1 = arr2D[0][n];
    int b1 = arr2D[1][n];
    int c1 = arr2D[2][n];

    int mymax = max(a1,max(b1,c1));
    if (mymax == 0){
        for (int i = 0; i < 3; i++){

            for (int j = n - 1; j>=0 ; j--){

                if (arr2D[i][j] > 0){
                    if (i == 0) {mymax = max(mymax,arr2D[i][j]);break;}
                    else {mymax = min(mymax,arr2D[i][j]); break;}
                }
            }
        }
    }
    cout << mymax;


}
