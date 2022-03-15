//7569 토마토(3차 배열.ver)
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

//디버깅용
void printArray(int height, int row, int col, vector<vector<vector<int>>> box){
    for(int k = 0 ; k < height ; k++){ //높이
        for(int i = 0 ; i < row ; i++){ //세로
            for(int j = 0 ; j < col ; j++){ //가로
                cout << box[k][i][j] << " ";
            }
            cout <<"\n";
        }
        cout << "\n";
    }
    cout << "\n";
}

int solution(int height, int row, int col, vector<vector<vector<int>>> box, queue<tuple<int, int, int>> dir) {
    int dh[6] = {0, 0, 0, 0, -1, 1}; //위, 아래, 왼쪽, 오른쪽, 앞, 뒤
    int dn[6] = {-1, 1, 0, 0, 0, 0};
    int dm[6] = {0, 0, -1, 1, 0, 0};
    while(!dir.empty()){
        int h = get<0>(dir.front());
        int n = get<1>(dir.front());
        int m = get<2>(dir.front());
        dir.pop();

        for(int i = 0 ; i < 6 ; i++){
            int nh = h + dh[i];
            int nn = n + dn[i];
            int nm = m + dm[i];

            //1. 범위 넘는 거 거름
            if(nh >= height || nh < 0 || nn >= row || nn < 0 || nm >= col || nm < 0)
                continue;

            //2. 벽이거나 이미 토마토가 익은 곳이면 거름
            if(box[nh][nn][nm] != 0){
                continue;
            }
            box[nh][nn][nm] = box[h][n][m] + 1;
            dir.push({nh, nn, nm});
        }
    }

    int day = 0;
    for(int k = 0 ; k < height ; k++){ //높이
        for(int i = 0 ; i < row ; i++){ //세로
            for(int j = 0 ; j < col ; j++){ //가로
                if(box[k][i][j]==0){
                    return -1;
                }
                day = max(day, box[k][i][j]);
            }
        }
    }
    return day - 1;
}

int main() {
    int m, n, h;
    cin >> m >> n >> h;
    vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m, 0)));
    queue<tuple<int, int, int>> dir;

    for(int k = 0 ; k < h ; k++){ //높이
        for(int i = 0 ; i < n ; i++){ //세로
            for(int j = 0 ; j < m ; j++){ //가로
                cin >> box[k][i][j];
                if(box[k][i][j]==1){
                    dir.push({k, i, j});
                }
            }
        }
    }

    printArray(h, n, m, box);
    cout << solution(h, n, m,box, dir);

    return 0;
}