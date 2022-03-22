#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<pair<int, int>> q;
    answer.assign(prices.size(), 0);
    
    for( int i = 0 ; i < prices.size() ; i++){
        q.push({prices[i], i});
    }
    
    while(!q.empty()){
        int price_val = q.front().first;
        int price_lo = q.front().second;
        q.pop();
        
        if(price_lo==prices.size()-1){
            //answer[price_lo]=0;
            break;
        }
            
        int sec = 0;
        for(int i= price_lo+1 ; i < prices.size() ; i++){
            sec++;
            if(prices[i]<price_val){
                break;
                
            }
        }
        
        answer[price_lo]=sec;
    }    
    
    return answer;
}