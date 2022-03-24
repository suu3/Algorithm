#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    
    
    for(int i = 0 ; i < scoville.size() ; i++)
        pq.push(scoville[i]);
    
    while(true){
        if(pq.top() >=K){
            break;
        }
        if(pq.size()==1){
            answer = -1;
            break;
        }
        
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int sum = first + second*2;
        pq.push(sum);
        answer++;
        
    }
    return answer;
}