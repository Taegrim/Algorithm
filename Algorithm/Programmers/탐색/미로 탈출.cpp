#include <iostream>

#include <string>
#include <vector>

using namespace std;


// 레버 -> 문
// 최소시간
// 레버까지 최소시간 + 문까지 최소시간

// 현재 위치, 목표 위치, 현재 깊이를 받아서 탐색
void DFS(vector<string>& maps, vector<vector<int>>& visited,
    int row, int col, int target_row, int target_col, int depth)
{
    if (target_row == row && target_col == col) {
        return;
    }

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    ++depth;

    for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < maps.size()
            && nc >= 0 && nc < maps[0].size()
            && maps[nr][nc] != 'X')
        {
            // 기존의 최소 거리보다 적게 걸린 경우만 탐색

            if (depth < visited[nr][nc]) {
                visited[nr][nc] = depth;
                DFS(maps, visited, nr, nc, target_row, target_col, depth);
            }
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;

    constexpr int MAX = 1e9;

    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), MAX));

    int start_row{}, start_col{};
    int lever_row{}, lever_col{};
    int exit_row{}, exit_col{};

    // 시작, 출구, 레버 위치 찾기
    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[0].size(); ++j) {
            if (maps[i][j] == 'S') {
                start_row = i;
                start_col = j;
            }
            else if (maps[i][j] == 'E') {
                exit_row = i;
                exit_col = j;
            }
            else if (maps[i][j] == 'L') {
                lever_row = i;
                lever_col = j;
            }
        }
    }

    visited[start_row][start_col] = 0;
    DFS(maps, visited, start_row, start_col, lever_row, lever_col, 0);
    answer += visited[lever_row][lever_col];

    if (visited[lever_row][lever_col] == MAX) {
        return -1;
    }

    // visited 초기화
    visited.assign(maps.size(), vector<int>(maps[0].size(), MAX));

    visited[lever_row][lever_col] = 0;
    DFS(maps, visited, lever_row, lever_col, exit_row, exit_col, 0);
    answer += visited[exit_row][exit_col];

    if (visited[exit_row][exit_col] == MAX) {
        return -1;
    }

    return answer;
}

int main()
{
    solution({ "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" });
    solution({ "LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO" });
}
