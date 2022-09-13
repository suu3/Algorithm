#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 1927 최소 힙
 * 
 */

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq;
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