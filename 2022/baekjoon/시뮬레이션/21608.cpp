//21608 상어 초등학교
#include <vector>
#include <iostream>
#include <set>

using namespace std;
int n;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void printArray(vector<vector<int>> &seat){
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ; j++) {
            cout << seat[i][j] << " ";
        }
        cout <<"\n";
    }
    cout <<"\n";
}
void find_seat(vector<vector<int>> &seat, vector<set<int>> &like, int student){
    int min_val = 0;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ; j++){

            //이미 배정된 자리면 넘김
            if(seat[i][j]>0)
                continue;

            //배정되지 않은 자리
            int count = 0;
            int no_seat = 0;
            for(int k = 0 ; k < 4 ; k++){
                int nr = i+dr[k];
                int nc = j+dc[k];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                if(seat[nr][nc]<=0){ //아무도 안 앉아있음: count 증가 될 일 없음
                    no_seat++;
                    continue;
                }

                if(like[student].find(seat[nr][nc]) != like[student].end()){
                    count++;
                };
            }
            switch(count){
                case 0:
                    seat[i][j] = 0;
                    break;
                case 1:
                    seat[i][j] = -10;
                    min_val = min(min_val, seat[i][j]);
                    break;
                case 2:
                    seat[i][j] = -100;
                    min_val = min(min_val, seat[i][j]);
                    break;
                case 3:
                    seat[i][j] = -1000;
                    min_val = min(min_val, seat[i][j]);
                    break;
                case 4:
                    seat[i][j] = -10000;
                    min_val = min(min_val, seat[i][j]);
                    break;
            }
            switch(no_seat){
                case 0:
                    seat[i][j] -= 0;
                    break;
                case 1:
                    seat[i][j] -= 1;
                    min_val = min(min_val, seat[i][j]);
                    break;
                case 2:
                    seat[i][j] -= 2;
                    min_val = min(min_val, seat[i][j]);
                    break;
                case 3:
                    seat[i][j] -= 3;
                    min_val = min(min_val, seat[i][j]);
                    break;
                case 4:
                    seat[i][j] -= 4;
                    min_val = min(min_val, seat[i][j]);
                    break;
            }

        }
    }


    for(int i = 0 ; i < n ;i++) {
        for (int j = 0; j < n; j++) {
            if(seat[i][j]==min_val){
                seat[i][j] = student;
                return;
            }
        }
    }
}
int print_answer(vector<vector<int>> &seat, vector<set<int>> &like){
    int sum = 0;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ; j++){
            int student = seat[i][j];
            int count = 0;
            for(int k = 0 ; k < 4 ; k++){
                int nr = i+dr[k];
                int nc = j+dc[k];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;
                if(like[student].find(seat[nr][nc]) != like[student].end()){
                    count++;
                };
            }
            switch(count){
                case 0:
                    sum += 0;
                    break;
                case 1:
                    sum += 1;
                    break;
                case 2:
                    sum += 10;
                    break;
                case 3:
                    sum += 100;
                    break;
                case 4:
                    sum += 1000;
                    break;
            }
        }
    }
    return sum;
}
int main() {
    cin >> n;
    int loop = n*n;
    vector<set<int>> like(n*n+1);
    vector<int> list;
    vector<vector<int>> seat(n, vector<int>(n, 0));
    while(loop--){
        int student;
        cin >> student;
        list.push_back(student);
        for(int i = 0 ; i < 4 ; i++){
            int l_student;
            cin >> l_student;
            like[student].insert(l_student);
        }
    }
    for(int i = 0 ; i < list.size() ; i++){
        find_seat(seat, like, list[i]);
        printArray(seat);

    }

    //만족도 총 합 출력
    int answer = print_answer(seat, like);
    cout << answer;

    return 0;
}