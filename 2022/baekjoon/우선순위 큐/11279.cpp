#include <iostream>
#include <queue>

using namespace std;

/**
 * 11279 최대 힙
 * 우선순위 큐 
 */

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    priority_queue<int> pq;
    while(n--){
        int x;
        cin >> x;
        
        if(pq.empty() && x==0){
            cout << "0\n";
            continue;
        }
        
        if(x==0){
            cout << pq.top()  << "\n";
            pq.pop();
        }else{
            pq.push(x);
        }
    }
    
    
	return 0;
}