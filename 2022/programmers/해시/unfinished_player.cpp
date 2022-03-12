#include <string>
#include <vector>
#include <set>
using namespace std;

string s_answer(multiset<string> pc, multiset<string> cp){
   string answer = "";
   for(auto iter = cp.begin(); iter!=cp.end(); iter++){
       multiset<string>::iterator it = pc.find(*iter);
       pc.erase(it);
   }
   return *pc.begin();
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> pc;
    multiset<string> cp;
    for(int i = 0 ; i < participant.size() ; i++){
        pc.insert(participant[i]);
    }
    for(int i = 0 ; i < completion.size() ; i++){
        cp.insert(completion[i]);
    }

    answer = s_answer(pc, cp);
    return answer;
}