//2606 바이러스
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    queue<int> bfs;
    while(m--){
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    vector<bool> visit(n+1, false);
    bfs.push(1);
    visit[1] = true;
    int count = -1;
    while(!bfs.empty()){
        int parent = bfs.front();
        bfs.pop();
        count++;
        for(int i = 0 ; i < graph[parent].size() ; i++){
            if(!visit[graph[parent][i]]){
                visit[graph[parent][i]] = true;
                bfs.push(graph[parent][i]);
            }
        }

    }

    cout << count;

    return 0;
}