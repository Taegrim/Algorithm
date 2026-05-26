#include <iostream>


#include <vector>

using namespace std;

// vector<int> -> n 기둥에서 k 기둥으로

// n-1까지 전부 2번 으로 옮기고 n을 3으로
// n-2까지 전부 1번으로 옮기고 n-1을 3으로
/// ... 반복

// 시작, 목표, 거쳐가는 기둥
void Hanoi(vector<vector<int>>& answer, int n, int start, int target, int temp)
{
    if (n == 1) {
        answer.push_back({ start, target });
        return;
    }

    // n-1까지 전부 거쳐가는 기둥으로 옮기기
    Hanoi(answer, n - 1, start, temp, target);

    // 현재 가장 큰 원판을 목표 기둥으로 옮기기
    answer.push_back({ start, target });

    // 거쳐가는 기둥의 원판들을 목표 기둥으로 옮기기
    Hanoi(answer, n - 1, temp, target, start);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    Hanoi(answer, n, 1, 3, 2);

    return answer;
}

int main()
{
    solution(2);
}
