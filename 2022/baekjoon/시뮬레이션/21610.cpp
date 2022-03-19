//21610 마법사 상어와 비바라기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solution(vector<vector<int>> &basket, vector<pair<int, int>> &dir, int n){
    queue<pair<int, int>> cloud;

    cloud.push({n-1, 0});
    cloud.push({n-1, 1});
    cloud.push({n-2, 0});
    cloud.push({n-2, 1});

    // ←, ↖, ↑, ↗, →, ↘, ↓, ↙
    int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};//좌표 이동
    int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    for(int i = 0 ; i < dir.size() ; i++) {
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        int move = dir[i].first;
        int distance = dir[i].second;

        queue<pair<int, int>> new_cloud;
        //1. 모든 구름이 d방향으로 s칸 이동한다.
        while (!cloud.empty()) {
            int row = cloud.front().first;
            int col = cloud.front().second;
            cloud.pop();

            row += (dr[move - 1] * distance);
            col += (dc[move - 1] * distance);

            //- 방향
            while (row < 0)
                row += n;
            while (col < 0)
                col += n;
            //+ 방항
            while (row >= n)
                row -= n;
            while (col >= n)
                col -= n;

            new_cloud.push({row, col}); //새 구름 좌표
        }

        //큐 교체
        while (!new_cloud.empty()) {
            cloud.push(new_cloud.front());
            new_cloud.pop();
        }

        //2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
        while (!cloud.empty()) {
            int row = cloud.front().first;
            int col = cloud.front().second;
            cloud.pop();

            basket[row][col]++;
            new_cloud.push({row, col});
            visit[row][col] = true;
        }
        //3.구름이 모두 사라진다.

        //4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다.
        // 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
        while (!new_cloud.empty()) {
            int row = new_cloud.front().first;
            int col = new_cloud.front().second;

            new_cloud.pop();

            //대각선 방향: 1, 3, 5, 7
            for (int j = 1; j <= 7; j += 2) {
                int check_r = row + dr[j];
                int check_c = col + dc[j];
                if (check_r < 0 || check_r >= n || check_c < 0 || check_c >= n) //범위 초과
                    continue;

                if (basket[check_r][check_c] > 0) {
                    basket[row][col]++;
                }
            }
        }

        // 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (!visit[j][k] && basket[j][k] >= 2) {
                    cloud.push({j, k});
                    basket[j][k] -= 2;
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> basket(n, vector<int>(n, 0));
    vector<pair<int,int>> dir;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> basket[i][j];
        }
    }

    while(m--){
        int d, s;
        cin >> d >> s;
        dir.push_back({d, s});
    }

    solution(basket, dir, n);

    int answer = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j ++){
            answer += basket[i][j];
        }
    }
    cout << answer;
}