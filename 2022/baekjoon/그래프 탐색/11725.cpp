//11725 트리의 부모 찾기
#include <iostream>
#include <vector>

using namespace std;

void solution(vector<vector<int>> &graph, int n, int parent, vector<int> &answer){
    if(graph[parent].size()==1 && parent != 1){ // leaf 노드
        return;
    }

    for(int i = 0 ; i < graph[parent].size(); i++){
        int child = graph[parent][i];
        if(answer[child]==0){ // 방문 X
            answer[child] = parent;
            solution(graph, n, child, answer);
        }
    }
}

int main() {
    int n;
    cin >> n; // 노드의 수
    vector<vector<int>> graph(n+1);
    for(int i = 0 ; i < n-1 ; i++){ // 간선의 수
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    vector<int> answer(n+1, 0);
    solution(graph, n, 1, answer);
    for(int i = 2 ; i <= n ;i++ ){
        cout << answer[i] << "\n";
    }
    return 0;
}