#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 대기실은 5개, 각각 5x5 사이즈
// 가로 세로 길이 합 2 이하 && 빈 테이블 -> 거리두기 X
// P, 0, X 로 사람, 빈테이블, 파티션 구분

constexpr int SIZE = 5;

bool BFS(const vector<string>& map, int row, int col)
{
    // row, col 과 깊이를 담는 큐
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));

    q.push({ {row, col}, 0 });
    visited[row][col] = true;

    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0 ,-1 };

    while (!q.empty()) {
        auto [pos, depth] = q.front();
        auto [r, c] = pos;
        q.pop();

        // 깊이는 2까지만
        if (depth >= 2) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int new_depth = depth + 1;

            if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE) {
                // 이미 방문했다면 넘기기
                if (visited[nr][nc]) {
                    continue;
                }

                // 사람이 있다면 바로 끝내기
                if (map[nr][nc] == 'P') {
                    return false;
                }

                // 빈 테이블일때만 해당 방향으로 탐색
                if (map[nr][nc] == 'O') {
                    visited[nr][nc] = true;
                    q.push({ {nr, nc}, new_depth });
                }
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    answer.reserve(SIZE);

    for (const auto& place : places) {
        bool IsKeepDistance = true;

        // 사람이 있는지 확인
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (IsKeepDistance && place[i][j] == 'P') {
                    IsKeepDistance = BFS(place, i, j);
                }
            }
        }

        if (IsKeepDistance) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }

    return answer;
}

int main()
{
    solution({
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
        });
}
