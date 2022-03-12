#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> genre_plays;
vector<string> genres_global;
vector<int> plays_global;

bool cmp(int &p1, int &p2) {
    //속한 노래가 많이 재생된 장르
    if(genre_plays[genres_global[p1]] != genre_plays[genres_global[p2]]){
        return genre_plays[genres_global[p1]] > genre_plays[genres_global[p2]];
    }

    //장르 같음
    //장르 내에서 많이 재생된 노래를 먼저 수록합니다.
    if(plays_global[p1]!=plays_global[p2]){
        return plays_global[p1] > plays_global[p2];
    }

    //재생횟수 같음
    // 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
    return p1 < p2;
}

vector<int> solution_answer(vector<string> genres, vector<int> plays){
    vector<int> answer;
    genres_global = genres;
    plays_global = plays;

    // 장르별 플레이 횟수 누적
    for(int i = 0 ; i < genres.size() ; i++){
        genre_plays[genres[i]] += plays[i];
        answer.push_back(i);
    }

    sort(answer.begin(), answer.end(), cmp);
    //두개씩 수록
    vector<int> real_answer;
    int count = 0;
    string current_genre = genres[answer[0]];
    for(int element : answer){
       if(genres[element]!=current_genre){ // 장르 바뀜
           count = 0;
           current_genre = genres[element];
       }
       if(count >= 2){
           continue;
       }
       
       real_answer.push_back(element);
       count++;
    }
    
    return real_answer;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    answer = solution_answer(genres, plays);
    return answer;
}