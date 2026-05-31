#include <iostream>

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 과제 시작시간 되면 시작
// 새로운 과제가 있다면 기존 과제 중단하고 새로운 과제 시작
// 과제 끝나면 남은 과제 시작
// 멈춰둔 과제 있다면 최근 과제부터 (스택)
// 과제 끝낸 순서대로 반환

// plans = [이름, 시작시간, 걸리는 시간(분)]

struct Homework{
    string name;
    int start_time;
    int play_time;
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    // 이름, 남은시간을 저장하는 스택
    stack<Homework> st;

    vector<Homework> homeworks;

    // 과제 순회
    for (const vector<string>& plan : plans) {
        Homework homework{};

        homework.name = plan[0];
        string hour_time = plan[1];
        homework.play_time = stoi(plan[2]);

        homework.start_time = 60 * stoi(hour_time.substr(0, 2)) + stoi(hour_time.substr(3, 2));

        homeworks.push_back(homework);
    }

    // 시작시간 순으로 정렬
    sort(homeworks.begin(), homeworks.end(), [](const Homework& a, const Homework& b) {
        return a.start_time < b.start_time;
        });

    
    Homework current_homework = homeworks[0];   // 현재 진행중인 과제

    // 새로운 과제 한번 쭉 탐색
    for(int i = 1; i < homeworks.size(); ++i){
        // 새로운 과제까지 걸리는 시간
        int elapsed_time = homeworks[i].start_time - current_homework.start_time;

        // 기존 과제 끝났는지 확인, 안끝났다면 스택으로
        if (elapsed_time < current_homework.play_time) {
            current_homework.play_time -= elapsed_time;
            st.push(current_homework);
        }
        // 끝났다면 answer 배열에 저장하고 체크
        else {
            answer.push_back(current_homework.name);

            // 현재 과제 끝냈다는 기준으로 남은 여유시간 갱신
            elapsed_time -= current_homework.play_time;

            // 과제가 끝나고도 시간이 남았다면 미뤄둔 과제 처리
            while (elapsed_time > 0 && !st.empty()) {
                current_homework = st.top();
                st.pop();

                // 기존 과제를 끝낼 수 있다면 여유시간 차감하고 스택에서 제거
                if (current_homework.play_time <= elapsed_time) {
                    answer.push_back(current_homework.name);
                    elapsed_time -= current_homework.play_time;
                }
                // 기존 과제가 아직 안끝났다면 과제 시간만 차감하고 스택에 다시 넣기
                else {
                    current_homework.play_time -= elapsed_time;
                    elapsed_time = 0;
                    st.push(current_homework);
                }
            }
        }

        // 새로운 과제 시작
        current_homework = homeworks[i];
    }

    // 마지막 과제는 뒤에 새로운 과제가 없어서 무조건 끝난것으로 처리
    answer.push_back(current_homework.name);

    // 미뤄둔 남은 과제들 처리
    while (!st.empty()) {
        answer.push_back(st.top().name);
        st.pop();
    }

    return answer;
}

int main()
{
    solution({ {"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"} });
    solution({ {"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"} });
    solution({ {"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"} });
}
