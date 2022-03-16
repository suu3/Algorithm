//1260 DFS 와 BFS
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(vector<bool> &dfs_visit, vector<vector<int>> &graph, int root){
    dfs_visit[root] = true;
    cout << root << " ";
    for(int i = 0 ; i < graph[root].size() ; i++){
        int next_node = graph[root][i];
        if(!dfs_visit[next_node]) {
            dfs(dfs_visit, graph, next_node);
        }
    }

}
void bfs(vector<vector<int>> &graph, int root){
    queue<int> q;
    vector<bool> visit(graph.size(), false);
    q.push(root);
    visit[root]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node <<" ";

        for(int i = 0 ; i < graph[node].size() ; i++){
            int next_node = graph[node][i];
            if(!visit[next_node]) {
                q.push(next_node);
                visit[next_node] = true;
            }
        }
    }

}

int main () {
    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<int>> graph(n+1);

    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
    for(int i = 1; i <=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }


    vector<bool> dfs_visit(graph.size(), false);
    dfs(dfs_visit, graph, v);
    cout <<"\n";
    bfs( graph, v);

    return 0;
}