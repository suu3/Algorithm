#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<pair<int, int>> st;
    for(int i = progresses.size()-1 ; i >= 0 ; i--){
        st.push({progresses[i], speeds[i]});
    }
    
        int day = 0;
    while(!st.empty()){
        int progress = st.top().first;
        int speed = st.top().second;
        st.pop();
        if(progress + speed*day >= 100){
            answer[answer.size()-1]++;
            cout << day << "\n";
            continue;
        }
        
        progress += speed*day;
        while(progress < 100){
            progress += speed;
            day++;
        }
        cout << day << "\n";
        answer.push_back(1);
    }
    return answer;
}