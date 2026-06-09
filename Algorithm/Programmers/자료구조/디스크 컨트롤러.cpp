#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 1. 번호, 요청시각, 소요 시간을 저장하는  대기 큐
// 2. 소요시간 짧은것 > 요청 시각 빠른 것 > 작업 번호 작은 것 우선순위
// 3. 작업 시작 시 끝낼때까지

// 종료 시간 - 요청시각 의 평균 구하기

struct S {
    int request_time;
    int duration;
};

struct Compare {
    bool operator()(const S& a, const S& b) const {
        if (a.duration == b.duration) {
            return a.request_time > b.request_time;
        }

        return a.duration > b.duration;
    }
};

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();

    // 대기 큐
    priority_queue<S, vector<S>, Compare> pq;

    // 구조체 배열
    vector<S> data;
    data.reserve(n);

    // 반환 시간
    vector<int> t_times;
    t_times.reserve(n);

    // 시간 순서대로 정렬을 한번 해야함
    for (const auto& job : jobs) {
        data.push_back({ job[0], job[1] });
    }
    sort(data.begin(), data.end(), [](const S& a, const S& b) {
        return a.request_time < b.request_time;
        });


    // 현재 시각, 작업 구조체 배열 인덱스, 완성한 작업 개수, 총 시간
    int current_time = 0;
    int index = 0;
    int completed = 0;
    int total_time = 0;

    // 시뮬레이션
    while (completed < n) {

        // 현재시각을 보고 요청된 작업 대기큐에 넣음
        while (index < n && data[index].request_time <= current_time) {
            pq.push(data[index]);
            ++index;
        }

        // 대기큐가 비어있다면 다음 작업 요청 시각으로 점프
        if (pq.empty()) {
            current_time = data[index].request_time;
            continue;
        }

        // 대기큐가 있다면 꺼내서 작업
        S job = pq.top();
        pq.pop();

        current_time += job.duration;

        total_time += current_time - job.request_time;

        ++completed;
    }

    return total_time / n;
}

int main()
{
    solution({ { 0,3 }, { 1, 9 }, { 3,5 } });
}
