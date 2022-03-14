#include <iostream>
#include <vector>

using namespace std;
#define MAX 1000000000
int min_diff =  MAX;
int n;

void permutation(vector<bool> visited, vector<pair<int, int>> selected, vector<pair<int, int>> material, int r, int depth){
    if(r==depth){
        int sum = 0;
        int product = 1;
        for (int i = 0; i < r; i++) {
            product *= selected[i].first;
            sum += selected[i].second;
        }
        min_diff = min(min_diff, abs(product - sum));
        return;
    }
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]) {
            visited[i]=true;
            selected[depth] = material[i];
            permutation(visited, selected, material,  r, depth + 1);
        }
    }

}

void solution(vector<pair<int, int>> material){
    for(int i = 0 ; i < n ; i++){
        vector<bool> visited(n, false);
        vector<pair<int, int>> selected(i+1, {0, 0});
        permutation(visited, selected, material,  i+1, 0);
    }
}

int main() {

    cin >> n;
    vector<pair<int, int>> material(n, {0, 0});
    for(int i = 0 ; i < n ; i++){
        int bit, sour;
        cin >> bit >> sour;
        material[i] = {bit, sour};
    }

    solution(material);
    cout << min_diff;

    return 0;
}
