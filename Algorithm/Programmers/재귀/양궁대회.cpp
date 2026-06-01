#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 가장 큰 점수차로 이겨야함
// 같은 점수는 1개 많게 쏴야함
// 지거나 비기면 -1 리턴

// 가장 큰 점수차로 우승할 수 있는 경우가 많다면 가장 낮은 점수를 많이 맞도록

vector<int> shoots;
vector<int> answer;
int max_diff = 0;

bool Lower(const vector<int>& current, const vector<int>& prev)
{
    // 뒤에서부터 화살 확인
    for (int i = 10; i >= 0; --i) {
        // 지금이 이전보다 낮은 점수에 화살이 많다면 true
        if (current[i] > prev[i]) {
            return true;
        }
        // 아니면 false
        else if (current[i] < prev[i]) {
            return false;
        }
    }

    return false;
}

void JudgeScore(const vector<int>& info)
{
    int ryan_score = 0;
    int apeach_score = 0;

    for (int i = 0; i < info.size(); ++i) {
        int score = 10 - i;

        // 라이언이 더 많이 쐈다면 라이언 점수
        if (shoots[i] > info[i]) {
            ryan_score += score;
        }
        // 라이언이 적게쐈거나 같은데 어피치가 쐈다면 어피치 점수
        else if (info[i] > 0) {
            apeach_score += score;
        }
    }

    int current_diff = ryan_score - apeach_score;

    // 지거나 비기는 경우
    if (current_diff <= 0) {
        return;
    }

    // 점수차 갱신할 수 있으면 갱신
    if (current_diff > max_diff) {
        max_diff = current_diff;
        answer = shoots;
    }
    // 점수차가 똑같다면 낮은 점수에 많이 쏜거로 변경
    else if (current_diff == max_diff && Lower(shoots, answer)) {
        answer = shoots;
    }
}

void DFS(const vector<int>& info, int index, int remain_arrow)
{
    if (index == info.size()) {
        // 남은 화살은 전부 낮은곳에 몰아주기
        shoots[10] += remain_arrow;

        JudgeScore(info);

        shoots[10] -= remain_arrow;

        return;
    }

    int count = info[index] + 1;

    // 현재 점수에 한발 더 쏘고 넘어감
    if (remain_arrow >= count) {
        shoots[index] = count;
        DFS(info, index + 1, remain_arrow - count);
        shoots[index] = 0;
    }

    // 안쏘고 넘어감
    DFS(info, index + 1, remain_arrow);
}

vector<int> solution(int n, vector<int> info) {
    shoots.assign(info.size(), 0);
    answer.clear();

    max_diff = 0;

    DFS(info, 0, n);

    if (answer.empty()) {
        return { -1 };
    }

    return answer;
}

int main()
{
    solution(5, { 2,1,1,1,0,0,0,0,0,0,0 });
    solution(1, { 1,0,0,0,0,0,0,0,0,0,0 });
    solution(9, { 0,0,1,2,0,1,1,1,1,1,1 });
    solution(10, { 0,0,0,0,0,0,0,0,3,4,3 });
}
