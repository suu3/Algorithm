//14502 연구소
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int max_val=0;
int n, m;

void printArray(vector<vector<int>> &board){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << board[i][j] <<" ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void bfs(vector<vector<int>> &board){
    //printArray(board);

    queue<pair<int, int>> q;
    vector<vector<int>> new_board(n, vector<int>(m, 0));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j]==2){
                q.push({i, j});
            }
            new_board[i][j] = board[i][j];
        }
    }

    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= n || nr < 0 || nc < 0 || nc >= m){
                continue;
            }
            if(new_board[nr][nc]!=0)
                continue;

            new_board[nr][nc] = 2;
            q.push({nr, nc});
        }
    }

    int count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(new_board[i][j]==0)
                count++;
        }
    }

    //cout << "count: " << count << "\n";
    max_val = max(max_val, count);
}

void backtracking(vector<vector<int>> &board, vector<vector<bool>> &visit, int depth){
    if(depth==3){
        bfs(board);
        return;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j]==0){
                board[i][j] = 1;
                //printArray(board);
                backtracking(board, visit, depth+1);
                board[i][j] = 0;
            }
        }
    }

}

int main(){
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<bool>> visit(n, vector<bool>(m, false));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
            if(board[i][j]!=0){
                visit[i][j] = true;
            }
        }
    }

    backtracking(board, visit, 0);

    cout << max_val;
    return 0;
}