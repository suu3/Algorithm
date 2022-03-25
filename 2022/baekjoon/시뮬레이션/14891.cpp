//14891 톱니바퀴
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void clock_turn(vector<vector<int>> &wheel, int current){
    vector<int> temp;
    temp.push_back(wheel[current][7]);

    for(int i = 0 ; i < 7 ;i++){
        temp.push_back(wheel[current][i]);
    }

    //바꿔치기
    for(int i = 0 ; i < 8 ; i++){
        wheel[current][i] = temp[i];
    }
}
void clock_turn_reverse(vector<vector<int>> &wheel, int current){
    vector<int> temp;
    for(int i = 1 ; i < 8 ;i++){
        temp.push_back(wheel[current][i]);
    }
    temp.push_back(wheel[current][0]);

    //바꿔치기
    for(int i = 0 ; i < 8 ; i++){
        wheel[current][i] = temp[i];
    }
}

void clock(vector<vector<int>> &wheel, int current, int dir){
    if(dir==1){
        clock_turn(wheel, current);
    }else{
        clock_turn_reverse(wheel, current);
    }
}

void solution(vector<vector<int>> &wheel, vector<pair<int, int>> &turn){
    for(int i = 0 ; i < turn.size() ; i++){
        queue<pair<int, int>> q;
        queue<pair<int, int>> final;
        bool visit[5] = {false};

        q.push({turn[i].first, turn[i].second});
        visit[turn[i].first] = true;

        final.push({turn[i].first, turn[i].second});

        while(!q.empty()){
            int current = q.front().first;
            int dir = q.front().second; // 시계:1, 반시계:-1
            q.pop();

            if(current == 1){
                if(wheel[1][2]!=wheel[2][6] && !visit[2]){
                    q.push({2, -dir});
                    final.push({2, -dir});
                    visit[2]=true;
                }
            }else if(current == 2){
                if(wheel[2][2]!=wheel[3][6] && !visit[3]){
                    //cout << "here ";
                    q.push({3, -dir});
                    final.push({3, -dir});
                    visit[3]=true;
                }
                if(wheel[2][6]!=wheel[1][2] && !visit[1]){
                    q.push({1, -dir});
                    final.push({1, -dir});
                    visit[1] = true;
                }
            }else if(current == 3){
                if(wheel[3][2]!=wheel[4][6] && !visit[4]){
                    q.push({4, -dir});
                    final.push({4, -dir});
                    visit[4] = true;
                }
                if(wheel[3][6]!=wheel[2][2] && !visit[2]){
                    q.push({2, -dir});
                    final.push({2, -dir});
                    visit[2] = true;
                }
            }else {
                if (wheel[4][6] != wheel[3][2] && !visit[3]) {
                    q.push({3, -dir});
                    final.push({3, -dir});
                    visit[3] = true;
                }
            }
        }

        //한꺼번에 회전
        while(!final.empty()){
            clock(wheel, final.front().first, final.front().second);
            final.pop();
        }
    }
}

int main() {
    vector<vector<int>> wheel(5, vector<int>(8, 0));

    for(int i = 1 ; i <= 4 ; i++){
        string status;
        cin >> status;
        for(int j = 0 ; j < status.length() ; j++){
            wheel[i][j] = status[j] - '0';
        }
    }

    int k;
    cin >> k;
    vector<pair<int,int>> turn;
    while(k--){
        int num, dir;
        cin >> num >> dir;
        turn.push_back({num, dir});
    }

    solution(wheel, turn);

    //점수 계산
    int score = 0;
    if(wheel[1][0]==1){
        score += 1;
    }
    if(wheel[2][0]==1){
        score += 2;
    }
    if(wheel[3][0]==1){
        score += 4;
    }
    if(wheel[4][0]==1){
        score += 8;
    }
    cout << score;
    return 0;
}