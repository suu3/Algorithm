#include <iostream>
#include <string.h>

using namespace std;

/*
* 1780 종이의 개수
*
*/

int N;
int map[2187][2187];
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
        ans[color + 1]++;
        return;
    }
 
    int div = n / 3;
 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2] ;

    return 0;
}
