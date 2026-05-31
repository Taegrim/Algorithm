#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 위 - 다음 알파벳 / 아래 - 이전 알파벳
// 왼쪽 - 커서 왼쪽으로 이동 / 오른쪽 - 커서 오른쪽으로 이동

// A가 아닌 모든 알파벳을 순회하는 최소 횟수 확인
// 각 자리별 최소 변환 횟수 확인

int solution(string name) {
    int answer = 0;

    const int SIZE = name.size();

    // 오른쪽으로만 눌렀을 경우 SIZE - 1
    int min_move = SIZE - 1;

    for (int i = 0; i < SIZE; ++i) {
        // 알파벳 변경 횟수 확인
        int up = name[i] - 'A';
        int down = 'Z' - name[i] + 1;

        answer += min(up, down);

        // i 이후로 연속된 A 구간 건너뛰기
        int next = i + 1;

        // 현재 위치에서 A구간 건너뛰기
        while (next < SIZE && name[next] == 'A') {
            ++next;
        }

        // i까지 오른쪽이동하고 다음 시작점까지 왼쪽으로 이동하는 경우
        // 오른쪽으로 i까지 왔다가 돌아오는 비용 : i * 2
        // 돌아와서 A시작점까지 왼쪽으로 가는 비용 : SIZE - next
        min_move = min(min_move, i * 2 + (SIZE - next));

        // 다음 시작점까지 왼쪽으로 갔다가 i까지 오른쪽으로 오는 경우
        // 다음 시작점까지 왼쪽으로 갔다가 돌아오는 비용 : (SIZE - next) * 2
        // 돌아와서 i까지 오른쪽으로 가는 비용 : i
        min_move = min(min_move, (SIZE - next) * 2 + i);
    }

    answer += min_move;

    return answer;
}

int main()
{
    solution("JEROEN");
    solution("JAN");
}
