#include <iostream>

#include <string>
#include <vector>
#include <limits>

using namespace std;

// 2차원 배열과 시작점, 끝점을 받아서 회전시키는 함수
int Rotation(vector<vector<int>>& maps, int start_row, int start_col, int end_row, int end_col)
{
    // 방향, 오른쪽, 아래, 왼쪽, 위
    int dir = 0;
    int dr[4] = { 0, 1, 0, -1 };
    int dc[4] = { 1, 0, -1, 0 };

    // 회전해야할 횟수, 테두리 길이
    int length = 2 * (end_row - start_row + 1) + 2 * (end_col - start_col + 1) - 4;

    int row = start_row;
    int col = start_col;

    int prev = maps[row][col];
    int min_val = numeric_limits<int>::max();

    // 앞의 내용을 이전 내용으로 덮어씀
    for (int i = 0; i < length; ++i) {
        int nr = row + dr[dir];
        int nc = col + dc[dir];

        // 현재 상태 저장, prev 갱신용
        int cur = maps[nr][nc];

        // 이전내용으로 덮어쓰고, prev 갱신, 최솟값 갱신
        maps[nr][nc] = prev;
        prev = cur;
        min_val = min(min_val, cur);

        row = nr;
        col = nc;

        // 모서리에 도달하면 방향 변경
        if ((nr == start_row && (nc == start_col || nc == end_col)) ||
            (nr == end_row && (nc == start_col || nc == end_col)))
        {
            ++dir;
        }
    }

    return min_val;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> maps(rows, vector<int>(columns));

    int num = 0;
    for (vector<int>& v : maps) {
        for (int& i : v) {
            i = ++num;
        }
    }

    for (const vector<int>& v : queries) {
        answer.push_back(Rotation(maps, v[0] - 1, v[1] - 1, v[2] - 1, v[3] - 1));
    }


    return answer;
}

int main()
{
    solution(6, 6, { { 2, 2, 5, 4 }, { 3, 3, 6, 6 }, { 5, 1, 6, 3 } });
    solution(3, 3, { { 1,1,2,2},{1,2,2,3},{2,1,3,2},{2,2,3,3 } });
    solution(100, 97, { {1,1,100,97} });
}
