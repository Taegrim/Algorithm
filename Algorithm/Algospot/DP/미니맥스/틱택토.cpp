#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;
vector<int> dp;

bool IsFinished(char turn)
{
    // 가로줄 검사
    for (int i = 0; i < 3; ++i)
    {
        bool is_finished = true;

        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] != turn)
            {
                is_finished = false;
                break;
            }
        }

        if (is_finished)
        {
            return true;
        }
    }

    // 세로줄 검사
    for (int i = 0; i < 3; ++i)
    {
        bool is_finished = true;

        for (int j = 0; j < 3; ++j)
        {
            if (board[j][i] != turn)
            {
                is_finished = false;
                break;
            }
        }

        if (is_finished)
        {
            return true;
        }
    }

    // 대각선 검사
    if ((board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
        || (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn))
    {
        return true;
    }

    return false;
}

// 9자리 3진수로 변환
int GetInteger()
{
    int ret = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            ret *= 3;
            if (board[i][j] == 'o')
            {
                ++ret;
            }
            else if (board[i][j] == 'x')
            {
                ret += 2;
            }
        }
    }
    return ret;
}

int CanWin(char turn)
{
    // 마지막에 상대방이 둬서 끝났다면 패배
    if (IsFinished('o' + 'x' - turn))
    {
        return -1;
    }

    int& ret = dp[GetInteger()];
    if (ret != -2)
    {
        return ret;
    }

    int val = 2;

    // 상대방의 모든 경우에서 최솟값이 되는 경우를 선택함
    // 상대방이 -1이면 상대방 패배, 0이면 무승부이기 때문
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = turn;
                val = min(val, CanWin('o' + 'x' - turn));
                board[i][j] = '.';

                // 상대방이 지는 수를 발견하면 내 승리 확정이므로 바로 종료
                if (val == -1)
                {
                    return ret = -val;
                }
            }
        }
    }

    // 플레이할 수 없거나, 비기는게 최선이면 비김
    if (val == 2 || val == 0)
    {
        return ret = 0;
    }

    // 최선의 경우가 상대방의 경우랑 반대
    return ret = -val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;

    while (t--)
    {
        board.assign(3, vector<char>(3, 0));
        dp.assign(20000, -2);

        int x_count{};
        int o_count{};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> board[i][j];

                if (board[i][j] == 'x')
                {
                    ++x_count;
                }
                else if (board[i][j] == 'o')
                {
                    ++o_count;
                }
            }
        }

        char turn = x_count > o_count ? 'o' : 'x';

        int ret = CanWin(turn);
        if (ret == 0)
        {
            cout << "TIE\n";
        }
        else if (ret == 1)
        {
            cout << turn << "\n";
        }
        else
        {
            cout << 'o' + 'x' - turn << "\n";
        }
    }
}
