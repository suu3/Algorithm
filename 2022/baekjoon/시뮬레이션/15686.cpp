//15686 치킨 배달
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n, m;
int sum_distance = 1000000;

vector<pair<int, int>> chicken_lo;
vector<vector<int>> chicken;
vector<pair<int, int>> home_start;

void backtracking(vector<pair<int, int>> &selected, vector<bool> &visit, int m, int index, int depth){

    if (m == 0)
    {
        int temp = 0; //도시의 치킨거리
        for(int i = 0 ; i < home_start.size() ; i++) {
            int d = 1000000; //집 하나의 치킨 거리
            for(int j = 0 ; j < selected.size() ; j++){
                int hr = home_start[i].first;
                int hc = home_start[i].second;
                int cr = selected[j].first;
                int cc = selected[j].second;
                d = min(d, abs(hr - cr ) + abs(hc - cc));
            }
            temp += d;
        }
        sum_distance = min(sum_distance, temp);
        return;
    }
    else if (depth == chicken_lo.size())
    {
        return;
    }

    selected[index] = chicken_lo[depth];
    backtracking(selected, visit, m - 1, index + 1, depth+1);
    backtracking(selected, visit, m, index, depth+1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    chicken.assign(n, vector<int>(n, 0));
    vector<pair<int, int>> selected(m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> chicken[i][j];
            if(chicken[i][j]==2){
                chicken_lo.push_back({i, j});
            }
            if(chicken[i][j]==1){
                home_start.push_back({i, j});
            }
        }
    }

    vector<bool> visit(chicken_lo.size(), false);
    backtracking(selected, visit, m, 0,0);
    cout << sum_distance;
    return 0;
}