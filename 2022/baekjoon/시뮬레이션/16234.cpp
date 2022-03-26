//16234 인구 이동
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, L, R;

vector<vector<pair<int, int>>> move_total;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void make_average(vector<vector<int>> &country, vector<vector<bool>> &visit, int i, int j){
    queue<pair<int, int>> close;
    vector<pair<int, int>> move;

    close.push({i, j});
    move.push_back({i, j});
    visit[i][j] = true;

    while(!close.empty()){
        int r = close.front().first;
        int c = close.front().second;
        close.pop();

        for(int k = 0 ; k < 4 ; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= n || nr < 0 || nc >= n || nc < 0 || visit[nr][nc])
                continue;

            int diff = abs(country[r][c] - country[nr][nc]);
            if(diff <= R && diff >= L){
                visit[nr][nc] = true;
                close.push({nr, nc});
                move.push_back({nr, nc});
            }
        }
    }

    move_total.push_back(move);
}

int solution(vector<vector<int>> &country){
    int days = -1;

    while(true){
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        days++;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(visit[i][j])
                    continue;
                make_average(country, visit, i, j);
            }
        }
        bool check = true;
        for(int i = 0 ; i < move_total.size() ; i++){
            if(move_total[i].size()!=1)
                check = false;
        }

        if(check)
            break;

        //평균으로 바꾸는 작업
        for(int i = 0 ; i < move_total.size() ; i++){
            int sum = 0;
            for(int j = 0 ; j < move_total[i].size() ; j++){
                sum += country[move_total[i][j].first][move_total[i][j].second];
            }
            for(int j = 0 ; j < move_total[i].size() ; j++){
                country[move_total[i][j].first][move_total[i][j].second] = sum / move_total[i].size();
            }
        }

        move_total.clear();
    }

    return days;
}

int main() {
    cin >> n >> L >> R;
    vector<vector<int>> country(n, vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> country[i][j];
        }
    }

    cout << solution(country);

    return 0;
}