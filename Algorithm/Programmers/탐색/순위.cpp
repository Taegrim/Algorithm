#include <iostream>

#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    // wins[i][j] -> i번 선수가 j번 선수를 이길 수 있음
    vector<vector<bool>> wins(n + 1, vector<bool>(n + 1));

    for (const auto& result : results) {
        wins[result[0]][result[1]] = true;
    }

    // k를 중간 경유지로 사용
    // i가 k를 이기고, k가 j를 이기면 i는 j를 이김
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (wins[i][k] && wins[k][j]) {
                    wins[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int count = 0;

        // i 선수가 이기거나 지는 횟수를 구함
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;

            if (wins[i][j] || wins[j][i]) {
                ++count;
            }
        }

        // n - 1 번 경기 횟수가 나오면 순위 확정 가능
        if (count == n - 1) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    solution(5, { {4, 3} ,{4, 2},{3, 2},{1, 2},{2, 5} });
}
