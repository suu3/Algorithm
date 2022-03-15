//2636 치즈
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

queue<pair<int, int>> bfs(vector<vector<int>> &board, int &n, int &m){
    queue<pair<int, int>> ch;
    queue<pair<int, int>> lo;
    vector<vector<bool>> visit(n, vector<bool>(m, false));

    ch.push({0, 0}); // board[0][0]은 가장자리이므로 치즈가 놓여있지 않다.
    visit[0][0] = true;

    while(!ch.empty()){
        int r = ch.front().first;
        int c = ch.front().second;
        ch.pop();

        if(board[r][c]==1){ //꺼냈는데 치즈임
            lo.push({r, c});
            continue;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= n || nr < 0 || nc >= m  || nc < 0)
                continue;

            if(!visit[nr][nc]){ //방문하지 않았으면
                visit[nr][nc] = true;
                ch.push({nr, nc});
            }
        }
    }

    return lo;
}
void solution(vector<vector<int>> &board, int &n, int &m){
    queue<pair<int, int>> lo;
    lo = bfs(board, n, m);

    int hour = 0;
    int final;
    while(!lo.empty()){
        final = 0;

        while(!lo.empty()){
            int r = lo.front().first;
            int c = lo.front().second;
            lo.pop();
            final++;
            board[r][c] = 0;
        }
        lo = bfs(board, n, m);
        hour++;
    }
    cout << hour << "\n" << final;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }

    solution(board, n, m);
    return 0;
}