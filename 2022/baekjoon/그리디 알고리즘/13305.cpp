// 13305 주유소
#include <iostream>

using namespace std;

int dist[100000];
int cost[100000];

int main(void){
    int n;
    long long total=0;
    long long cur;
    
    cin >> n;
    
    for(int i=1; i<n; i++){
        cin >> dist[i];
    }
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    cur = cost[0];
    total = cur * dist[1];
    
    for(int i=1; i<n; i++){
        if(cur < cost[i]){
            total += cur * dist[i+1];
        }
        else {
            cur = cost[i];
            total += cur * dist[i+1];
        }
    }
    cout << total;
}