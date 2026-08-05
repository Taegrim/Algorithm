#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> buttons
{
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

vector<int> clocks;

int answer;
constexpr int MAX = 10000;

void PushButton(const vector<int>& button, int count)
{
    for (int i : button)
    {
        clocks[i] = (clocks[i] + 3 * count) % 12;
        if (clocks[i] == 0)
        {
            clocks[i] = 12;
        }
    }
}

void ResetButton(const vector<int>& button, int count)
{
    for (int i : button)
    {
        clocks[i] = (clocks[i] - 3 * count + 12) % 12;
        if (clocks[i] == 0)
        {
            clocks[i] = 12;
        }
    }
}

bool CheckClocks()
{
    for (int clock : clocks)
    {
        if (clock != 12)
        {
            return false;
        }
    }
    return true;
}

void DFS(int idx, int count)
{
    // 이미 찾은 횟수보다 커지면 탐색할필요 X
    if (count >= answer)
    {
        return;
    }

    // 모든 버튼을 체크했으면 확인
    if (idx >= buttons.size())
    {
        if (CheckClocks())
        {
            answer = min(answer, count);
        }
        return;
    }

    // 4번 누르면 원복되므로 0~3 번만 버튼을 누른다 가정
    for (int i = 0; i < 4; ++i)
    {
        PushButton(buttons[idx], i);

        DFS(idx + 1, count + i);

        ResetButton(buttons[idx], i);
    }
}

int main()
{
    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        clocks.assign(16, 0);
        answer = MAX;

        for (int i = 0; i < 16; ++i)
        {
            cin >> clocks[i];
        }

        DFS(0, 0);

        if (answer == MAX)
        {
            answer = -1;
        }

        cout << answer << "\n";
    }
}
