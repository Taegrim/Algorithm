#include <iostream>

#include <vector>

using namespace std;


vector<int> solution(int n) {
    vector<int> answer;
    int total = n * (n + 1) / 2;
    answer.reserve(total);

    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(i + 1, 0);
    }

    // 아래, 오른쪽, 위 방향
    int dr[3] = {1, 0, -1};
    int dc[3] = { 0, 1, -1 };

    int row{}, col{}, dir{};

    for (int i = 1; i <= total; ++i) {
        v[row][col] = i;

        int next_row = row + dr[dir];
        int next_col = col + dc[dir];

        // 범위를 벗어나거나, 이미 채워진 칸이면 방향 ++
        if (next_row >= n || next_row < 0 ||
            next_col > next_row || next_col < 0 ||
            v[next_row][next_col] != 0)
        {
            dir = (dir + 1) % 3;
        }

        row += dr[dir];
        col += dc[dir];
    }

    for (int i = 0; i < n; ++i) {
        answer.insert(answer.end(), v[i].begin(), v[i].end());
    }

    return answer;
}

int main()
{
    solution(4);
    solution(5);
    solution(6);
}
