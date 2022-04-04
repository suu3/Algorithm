#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string &p1, string &p2){
    string p1_temp = p1 + p2;
    string p2_temp = p2 + p1;
    return p1_temp > p2_temp;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for(int i = 0 ; i < numbers.size() ; i++){
        str.push_back(to_string(numbers[i]));
    }
    sort(str.begin(), str.end(), cmp);
    for(int i =0; i< str.size() ; i++){
        answer += str[i];
    }
    
    if(answer[0]=='0') answer="0";
    return answer;
}
