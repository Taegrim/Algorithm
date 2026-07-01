#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 특정 열 뒤집기
void FlipRow(vector<vector<int>>& a, int r)
{
    for (int c = 0; c < a[0].size(); ++c)
    {
        a[r][c] = 1 - a[r][c];
    }
}

// 특정 행 뒤집기
void FlipCol(vector<vector<int>>& a, int c)
{
    for (int r = 0; r < a.size(); ++r)
    {
        a[r][c] = 1 - a[r][c];
    }
}

bool IsBoardEqual(const vector<vector<int>>& a, const vector<vector<int>>& b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[0].size(); ++j)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int CheckBoard(vector<vector<int>> board, const vector<vector<int>>& target, bool first_row)
{
    int n = board.size();
    int m = board[0].size();
    int count = 0;

    // 첫번째 행을 뒤집고 시작할지 판단
    if (first_row)
    {
        FlipRow(board, 0);
        ++count;
    }

    // 첫번째 행을 기준으로 열 뒤집기
    // 다른것이 있다면 해당 칸에 해당하는 열 뒤집기
    for (int col = 0; col < m; ++col)
    {
        if (board[0][col] != target[0][col])
        {
            FlipCol(board, col);
            ++count;
        }
    }

    // 첫번째 열을 기준으로 행 뒤집기
    // 다른것이 있다면 해당 칸에 해당하는 행 뒤집기
    for (int row = 0; row < n; ++row)
    {
        if (board[row][0] != target[row][0])
        {
            FlipRow(board, row);
            ++count;
        }
    }

    if (IsBoardEqual(board, target))
    {
        return count;
    }

    return 1e9;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    // 첫번째 행을 뒤집고 시작하는지, 안뒤집고 시작하는지로 확인
    int answer = min(
        CheckBoard(beginning, target, false),
        CheckBoard(beginning, target, true)
    );

    if (answer == 1e9)
    {
        answer = -1;
    }

    return answer;
}

int main()
{
    solution({{0, 1, 0, 0, 0}, {1, 0, 1, 0, 1}, {0, 1, 1, 1, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}},
        {{0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}} );
    solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{1, 0, 1}, {0, 0, 0}, {0, 0, 0}} );
}
