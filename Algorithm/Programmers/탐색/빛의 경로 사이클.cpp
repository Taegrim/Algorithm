#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// S - 직진, L - 좌회전, R - 우회전, 격자 바깥가면 반대쪽에서 나옴

// 맨 처음 시작지점, 발사 방향과 똑같아지면 사이클 완료
// 1,1에서 빛을 발사했을 때 사이클이 몇개 생성되는지

int GetDir(int dir, char node)
{
    if (node == 'L') {
        return (dir + 3) % 4;
    }

    if (node == 'R') {
        return (dir + 1) % 4;
    }

    return dir;
}

int GetCycleLength(const vector<string>& grid, vector<vector<vector<bool>>>& visited,
    int sr, int sc, int start_dir)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // up, right, down, left
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    int row = sr;
    int col = sc;
    int dir = start_dir;
    int length = 0;

    while (!visited[row][col][dir]) {
        visited[row][col][dir] = true;
        ++length;

        dir = GetDir(dir, grid[row][col]);

        // 음수로 갔을 때 rows - 1 로 되돌리기 위해 rows를 더하고 나머지를 구함
        row = (row + dr[dir] + rows) % rows;
        col = (col + dc[dir] + cols) % cols;
    }

    return length;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    int rows = grid.size();
    int cols = grid[0].size();


    // 2차원 배열 + 방향을 저장하는 벡터
    vector<vector<vector<bool>>> visited(
        rows,
        vector<vector<bool>>(cols, vector<bool>(4, false))
    );

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            for (int dir = 0; dir < 4; ++dir) {
                // 이미 방문한 노드에서 해당 방향으로 빛을 발사했다면 건너뛰기
                if (visited[r][c][dir]) {
                    continue;
                }

                answer.push_back(GetCycleLength(grid, visited, r, c, dir));
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    solution({ "SL", "LR" });
    solution({ "S" });
    solution({ "R", "R" });
}
