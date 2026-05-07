#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void bfs(vector<string>& maps, vector<int>& answer, int row, int col)
{
    queue<pair<int, int>> q;

    q.push({ row, col });

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    int food = maps[row][col] - '0';
    maps[row][col] = 'X';

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < maps.size() && nc < maps[0].size()) {
                if (maps[nr][nc] != 'X') {
                    food += maps[nr][nc] - '0';
                    q.push({ nr, nc });
                    maps[nr][nc] = 'X';
                }
            }
        }
    }

    answer.push_back(food);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[i].size(); ++j) {
            if (maps[i][j] != 'X') {
                bfs(maps, answer, i, j);
            }
        }
    }

    if (answer.empty()) {
        answer.push_back(-1);
    }
    else {
        sort(answer.begin(), answer.end());
    }

    return answer;
}

int main()
{
    solution({ "X591X","X1X5X","X231X", "1XXX1" });
    solution({ "XXX","XXX","XXX" });
}
