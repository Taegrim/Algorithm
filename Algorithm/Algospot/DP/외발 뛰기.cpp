#include <iostream>
#include <vector>

using namespace std;

int n;

vector<vector<int>> board;
vector<vector<int>> dp;

bool F(int row, int col)
{
    // 도착
    if (row == n - 1 && col == n - 1)
    {
        return true;
    }

    // 보드 바깥은 못감
    if (row >= n || col >= n)
    {
        return false;
    }

    int& ret = dp[row][col];
    if (ret != -1)
    {
        return ret;
    }

    int len = board[row][col];

    // 아래, 오른쪽 둘중 하나라도 가능하면 true
    return ret = (F(row + len, col) || F(row, col + len));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int loop;
    cin >> loop;

    while (loop--)
    {
        cin >> n;

        board.assign(n, vector<int>(n, 0));
        dp.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> board[i][j];
            }
        }

        cout << (F(0, 0) ? "YES" : "NO") << "\n";
    }
}
