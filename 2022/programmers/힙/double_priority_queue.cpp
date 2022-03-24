#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq; //최대힙
    
    
    for(int i = 0 ; i < operations.size() ; i++){
        char di = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if(di=='I'){
            pq.push(num);
            cout << "insert num: " << num << "\n";
        }else if(di=='D'){
            if(num==1){
                //최댓값
                if(!pq.empty()) // <- 빼먹으면 세그폴트 에러 항상 주의~
                    pq.pop();
            }else{
                //최소값
                priority_queue<int> temp;
                
                while(pq.size()>1){
                    temp.push(pq.top());
                    pq.pop();
                }
                
                if(!pq.empty())
                    pq.pop();
                
                while(!temp.empty()){
                    pq.push(temp.top());
                    temp.pop();
                }
            }
        }        
    }
    if(pq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(pq.top());
        while(pq.size()>1){
            pq.pop();
        }
        answer.push_back(pq.top());        
    }
    
    return answer;
}