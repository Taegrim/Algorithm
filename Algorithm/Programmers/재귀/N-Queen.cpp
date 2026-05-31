#include <iostream>

#include <vector>
#include <cmath>

using namespace std;

int answer{};

void DFS(vector<int>& queens, int row, int n)
{
    if (row == n) {
        ++answer;
        return;
    }

    vector<bool> cols(n, true);

    // 이전에 배치한 퀸들로 배치 가능한 타일만 남기기
    for (int queen_row = 0; queen_row < row; ++queen_row) {
        int queen_col = queens[queen_row];

        // 같은 열 배치 불가능
        cols[queen_col] = false;


        // 대각선 배치 불가능
        int diff = row - queen_row;

        if (queen_col - diff >= 0) {
            cols[queen_col - diff] = false;
        }

        if (queen_col + diff < n) {
            cols[queen_col + diff] = false;
        }
    }

    for (int col = 0; col < n; ++col) {
        if (cols[col]) {
            queens[row] = col;
            DFS(queens, row + 1, n);
        }
    }
}

int solution(int n) {
    answer = 0;

    // 퀸의 위치를 담는 컨테이너 queens
    // index가 행의 역할을 함
    vector<int> queens(n, -1);

    DFS(queens, 0, n);

    return answer;
}

int main()
{
    solution(4);
}
