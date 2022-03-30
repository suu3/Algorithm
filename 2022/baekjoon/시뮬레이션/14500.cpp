//14500 테트로미노
#include <iostream>
#include <vector>

using namespace std;
int max_value = 0;
int n, m;
vector<vector<int>> board;
vector<pair<int, int>> turn_zero(int r, int c, int dr[4], int dc[4]){
    vector<pair<int, int>> temp;
    for(int i = 0 ; i < 4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >=m)
            continue;

        temp.push_back({nr, nc});
    }
    return temp;
}
void solution(int r , int c) {
    int dr[19][4] = {{0, 0, 0, 0},
                     {0, 1, 2, 3}, // 1번 도형
                     {0, 0, 1, 1}, // 2번 도형
                     {0, 1, 2, 2},
                     {0, 0, 0, 1},
                     {0, 0, 1, 2},
                     {0, 1, 1, 1}, // 3번 도형
                     {0, 1, 1, 2},
                     {0, 0, 1, 1}, // 4번 도형
                     {0, 0, 0, 1},
                     {0, 1, 1, 2},
                     {0, 1, 1, 1},
                     {0, 1, 1, 2}, //5번 도형
                     {0, 1, 1, 2},
                     {0, 0, 1, 1},
                     {0, 1, 2, 2},
                     {0, 0, 0, 1},
                     {0, 0, 1, 2},
                     {0, 1, 1, 1}};
    int dc[19][4] = {{0, 1, 2, 3},
                     {0, 0, 0, 0}, // 1번 도형
                     {0, 1, 0, 1}, // 2번 도형
                     {0, 0, 0, 1},
                     {0, 1, 2, 0},
                     {0, 1, 1, 1},
                     {2, 0, 1, 2}, // 3번 도형
                     {0, 0, 1, 1},
                     {1, 2, 0, 1}, // 4번 도형
                     {0, 1, 2, 1},
                     {1, 0, 1, 1},
                     {1, 0, 1, 2},
                     {0, 0, 1, 0}, //5번 도형
                     {1, 0, 1, 0},
                     {0, 1, 1, 2},
                     {1, 1, 0, 1},
                     {0, 1, 2, 2},
                     {0, 1, 0, 0},
                     {0, 0, 1, 2}};

    for (int i = 0; i < 19; i++) {
        vector<pair<int, int>> tetro = turn_zero(r, c, dr[i], dc[i]);
        int sum = 0;
        if (tetro.size() < 4) continue; // 범위를 넘어버림.
        for (int k = 0; k < 4; k++) {
            int row = tetro[k].first;
            int col = tetro[k].second;
            sum += board[row][col];
        }
        max_value = max(max_value, sum);
        cout << max_value << "\n";
    }
}

//회전 4번 가능
int main() {
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            solution(i, j);
        }
    }

    cout << max_value;
    return 0;
}