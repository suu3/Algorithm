//19538 루머
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

queue<tuple<int, int, int>> q; //주변인, 근원지
queue<int> root;
vector<int> t; // 정답 배열

void bfs(vector<vector<int>> &adj){
    while(!q.empty()) {

        while(!q.empty()){
            int rumor = get<0>(q.front());
            int parent = get<1>(q.front());
            int belief = get<2>(q.front());
            q.pop();

            if(belief*2 >= adj[rumor].size()){ //과반수가 루머를 믿음
                t[rumor] = min(t[rumor], t[parent]+1);
                root.push(rumor);
            }
        }
        while(!root.empty()){
            int rumor = root.front();
            root.pop();
            for(int i = 0 ; i < adj[rumor].size() ; i ++){
                int child = adj[rumor][i];
                if(t[child]==200001){ // 아직 루머를 믿지 않는주변인이다
                    int new_belief = 0;
                    for(int j = 0 ; j < adj[child].size() ; j++){
                        if(t[adj[child][j]]!=200001) new_belief++;
                    }
                    q.push({child, rumor, new_belief});
                }
            }
        }
    }
}


int main(){
    int N, M, temp;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<vector<int>> adj(N+1);  // 주변인인가?
    t.assign(N+1 , 200001); //정답 배열
    for(int i = 1 ; i <= N ; i++){
        while(true){
            cin >> temp;
            if(temp == 0){
                break;
            }
            adj[i].push_back(temp);
        }
    }
    cin >> M;
    while(M--){
        int first;
        cin >> first;
        t[first] = 0; // 최초 유포자
        root.push(first);
    }

    while(!root.empty()){
        int first = root.front();
        root.pop();
        for(int i = 0 ; i < adj[first].size() ; i++) {
            int belief = 0;
            int child = adj[first][i];
            for(int j = 0 ; j < adj[child].size() ; j++){
                if(t[adj[child][j]]!=200001) belief++;
            }
            if(t[child]==200001) { // 아직 루머를 믿지 않는 주변인
                q.push({child, first, belief});
            }
        }

    }

    bfs(adj);

    for(int i = 1 ; i <= N ; i++){
        if(t[i]==200001) t[i] = -1;
        cout << t[i] << " ";
    }

    return 0;
}
