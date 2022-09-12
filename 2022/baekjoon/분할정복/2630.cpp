#include <iostream>
#include <string.h>

using namespace std;

/*
* 2630 색종이 만들기 (분할 정복)
* 정사각형 종이가 모두 같은 숫자면 count하고, 
* 아니면 종이를 네 등분해 재귀를 돌린다. 
*
*/

int N;
int map[128][128];
int ans[2];
 
bool is_all_same(int x, int y, int n) {
    
    int check = map[x][y];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[x + i][y + j] != check) {
                return false;
            }
        }
    }
 
    return true;
}
 
void color_paper(int x, int y, int n) {
 
    if (is_all_same(x, y, n)) {
        int color = map[x][y];
        ans[color]++;
        return;
    }
 
    int div = n / 2;
 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            color_paper(x + div * i, y + div * j, div);
        }
    }
}

int main() {
 
    N = 0;
    memset(map, 0, sizeof(map));
    memset(ans, 0, sizeof(ans));
 
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }


    color_paper(0, 0, N);
    cout << ans[0] << "\n" << ans[1] ;

    return 0;
}
