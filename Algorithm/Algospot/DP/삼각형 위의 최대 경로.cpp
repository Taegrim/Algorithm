#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> dp;
int n;

int F(int row, int col)
{
    // 맨 아래 도달하면 종료
    if (row == n - 1)
    {
        return v[row][col];
    }

    int& ret = dp[row][col];
    if (ret != -1)
    {
        return ret;
    }

    // F(r, c) = max(F(r+1, c), F(r+1, c+1)) + v[r][c]

    return ret = max(F(row + 1, col), F(row + 1, col + 1)) + v[row][col];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        v.assign(n, vector<int>(n, -1));
        dp.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                cin >> v[i][j];
            }
        }

        cout << F(0, 0) << "\n";
    }
}
