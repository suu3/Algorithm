#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int arr[n+1][n+1];
    memset(arr, 0, sizeof(arr));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int temp;
            cin >> temp;
            arr[i][j] = temp + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    for(int i = 0 ; i < m ; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1] << "\n";
    }

    return 0;
}