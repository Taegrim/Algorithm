#include <iostream>

#include <string>
#include <vector>

using namespace std;

// r에서 시작, 목표 : G, 장애물 : D

constexpr int MAX = 1e9;

bool CheckBoard(const vector<string>& board, int row, int col)
{
    if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()) {
        if (board[row][col] != 'D') {
            return true;
        }
    }
    return false;
}

void DFS(const vector<string>& board, vector<vector<int>>& visited,
    int row, int col, int goal_row, int goal_col, int depth)
{
    visited[row][col] = depth;

    if (row == goal_row && col == goal_col) {
        return;
    }

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; ++i) {
        int nr = row;
        int nc = col;

        // 한 방향으로 직진하다가 충돌하면 종료
        while (CheckBoard(board, nr + dr[i], nc + dc[i])) {
            nr += dr[i];
            nc += dc[i];
        }

        // 가려는 곳의 시도횟수가 현재 시도횟수보다 클때만 진입
        if (depth + 1 < visited[nr][nc]) {
            DFS(board, visited, nr, nc, goal_row, goal_col, depth + 1);
        }
    }
}

int solution(vector<string> board) {
    int answer = 0;

    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), MAX));

    int start_row{}, start_col{};
    int goal_row{}, goal_col{};

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 'R') {
                start_row = i;
                start_col = j;
            }
            else if (board[i][j] == 'G') {
                goal_row = i;
                goal_col = j;
            }
        }
    }

    DFS(board, visited, start_row, start_col, goal_row, goal_col, 0);

    answer = visited[goal_row][goal_col];
    if (answer == MAX) {
        answer = -1;
    }

    return answer;
}

int main()
{
    solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
    solution({ ".D.R", "....", ".G..", "...D" });
}
