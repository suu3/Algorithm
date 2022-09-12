#include <iostream>
#include <string.h>

using namespace std;

/*
* 2740 행렬 곱셈
*
*/



int main() {
 
    int n, m;
    cin >> n >> m;
    int A[n][m];
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            cin >> A[i][j];
        }
    }
    
    int bm, bk;
    cin >> bm >> bk;
    int B[bm][bk];

    for(int i = 0 ; i < bm ; i ++){
        for(int j = 0 ; j < bk ; j++){
            cin >> B[i][j];
        }
    }
    
    int ans[n][bk];
    memset(ans, 0, sizeof(ans));
    
    //행렬의 곱셈

    for(int k = 0 ; k < bk ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int a = A[i][j];
                int b = B[j][k];
                ans[i][k] += a * b;
            }
        }
    }
    
    // 정답 출력
    for(int i = 0 ; i < n ; i++){
        for(int k = 0 ; k < bk ; k++){
            cout << ans[i][k] << " ";
        }
        cout << "\n";
    }

    return 0;
}
