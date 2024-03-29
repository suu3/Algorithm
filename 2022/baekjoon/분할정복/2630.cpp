#include <iostream>
#include <string.h>

using namespace std;

/*
* 1992 쿼드 트리 (분할 정복)
*
*/

int N;
string map[65];
 
bool is_all_same(int x, int y, int n) {
    
    char check = map[x][y];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[x + i][y + j] != check) {
                return false;
            }
        }
    }
 
    return true;
}
 
void quard_tree(int x, int y, int n) {
 
    if (is_all_same(x, y, n)) {
        int num = map[x][y];
        cout << num;
        return;
    }
 
    int div = n / 2;
 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "(";
            quard_tree(x + div * i, y + div * j, div);
            cout << ")";
        }
    }
}

int main() {
 
    N = 0;
    memset(map, 0, sizeof(map));
    memset(ans, 0, sizeof(ans));
 
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }


    quard_tree(0, 0, N);

    return 0;
}
