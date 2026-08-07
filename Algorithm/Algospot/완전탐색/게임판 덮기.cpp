#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> v;
int ret;
int r, c;

// types[4][3]
vector<vector<pair<int, int>>> types =
{
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

// 해당 타입의 블록으로 채울 수 있는지 확인
bool CanFill(const vector<pair<int, int>>& type, int row, int col)
{
    for(const auto& [dr, dc] : type)
    {
        int nr = row + dr;
        int nc = col + dc;

        if (nr < 0 || nc < 0 || nr >= r || nc >= c) return false;
        if (v[nr][nc] != '.') return false;
    }
    return true;
}

// 해당 타입의 블록으로 채우기
void FillBoard(const vector<pair<int, int>>& type, int row, int col, char ch)
{
    for (const auto& [dr, dc] : type)
    {
        v[row + dr][col + dc] = ch;
    }
}

void DFS()
{
    // 빈칸 찾기
    int row = -1;
    int col = -1;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (v[i][j] == '.')
            {
                row = i;
                col = j;
                break;
            }
        }

        if (row != -1)
        {
            break;
        }
    }

    // 돌았는데도 white를 못찾으면 전부 채운것
    if (row == -1)
    {
        ++ret;
        return;
    }

    for (const auto& type : types)
    {
        if (!CanFill(type, row, col)) continue;

        FillBoard(type, row, col, '#');
        DFS();
        FillBoard(type, row, col, '.');
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int loop;
    cin >> loop;

    while (loop--)
    {
        cin >> r >> c;

        v.assign(r, vector<char>(c));
        ret = 0;

        int empty = 0;

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cin >> v[i][j];
                if (v[i][j] == '.')
                {
                    ++empty;
                }
            }
        }

        if (empty % 3 != 0)
        {
            cout << 0 << "\n";
            continue;
        }

        DFS();

        cout << ret << "\n";
    }
}
