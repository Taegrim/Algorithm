#include <iostream>
#include <vector>

using namespace std;

vector<char> dp;
vector<int> moves;

int Cell(int r, int c)
{
    return 1 << (r * 5 + c);
}

void PreCalc()
{
    // 5x5 보드라 0~4 까지만 검사,
    // 우측 아래 방향으로 사각형을 배치한다 가정함
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int cells[]
            {
                Cell(i, j),
                Cell(i, j + 1),
                Cell(i + 1, j),
                Cell(i + 1, j + 1)
            };

            int square = cells[0] | cells[1] | cells[2] | cells[3];

            for (int k = 0; k < 4; ++k)
            {
                moves.push_back(square - cells[k]);
            }
        }
    }

    // 가로 2칸
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            moves.push_back(Cell(i, j) | Cell(i, j + 1));
        }
    }

    // 세로 2칸
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            moves.push_back(Cell(i, j) | Cell(i + 1, j));
        }
    }
}

char Play(int board)
{
    char& ret = dp[board];
    if (ret != -1)
    {
        return ret;
    }

    for (int move : moves)
    {
        // 현재 보드와 겹치지 않으면 배치 가능한 것
        if ((board & move) != 0)
        {
            continue;
        }

        // 보드에 블록을 놓고 상대방 차례인데 진다면 내 승리
        if (!Play(board | move))
        {
            return ret = 1;
        }
    }

    // 블록을 배치할 수 없다면 패배
    return ret = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    PreCalc();
    dp.assign(1 << 25, -1);

    while (t--)
    {

        int board = 0;

        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                char c;
                cin >> c;

                if (c == '#')
                {
                    board |= Cell(i, j);
                }
            }
        }

        cout << (Play(board) ? "WINNING" : "LOSING") << "\n";
    }
}
