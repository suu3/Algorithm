#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;
typedef tuple<int, int, int, int> ci;

int current_time = 0;

struct cmp {
    bool operator()(ci& p1, ci& p2) {
        if (get<2>(p1) != get<2>(p2))
            return get<2>(p1) > get<2>(p2);
        return get<3>(p1) > get<3>(p2);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    priority_queue<ci, vector<ci>, cmp> pq;

    for (int i = 0; i < jobs.size(); i++) {
        pq.push({ jobs[i][0], jobs[i][1], jobs[i][0], jobs[i][0] + jobs[i][1] });
    }

    while (!pq.empty()) {
        int start = get<0>(pq.top());
        int time = get<1>(pq.top());
        int start_work = get<2>(pq.top());
        int end_work = get<3>(pq.top());

        pq.pop();
        if (current_time < start)
            answer += (end_work - start_work);
        else
            answer += (abs(start - current_time) + time);
        cout << answer << "\n";

        //현재 시간 갱신
        current_time = end_work;

        priority_queue<ci, vector<ci>, cmp> temp;
        while (!pq.empty()) {
            int start = get<0>(pq.top());
            int time = get<1>(pq.top());
            int start_work, end_work;
            if (current_time <= start) {
                start_work = start; // 시작지점까지 기다렸다가 시작
            }
            else {
                start_work = current_time; // 바로 시작
            }
            end_work = start_work + time;
            pq.pop();
            temp.push({ start, time, start_work, end_work });
        }
        pq.swap(temp);
    }


    return answer / jobs.size();
}