#include <iostream>
#include <vector>

using namespace std;

constexpr int EMPTY = -1e9;

int n;
vector<vector<int>> dp;
vector<int> numbers;

// 현재 내 차례에서 최선을 다했을 때 얻을 수 있는 점수 차이의 최댓값
// 내 점수 - 상대방 점수
int PlayGame(int left, int right)
{
    // 모든 수가 사라지면 종료
    if (left > right)
    {
        return 0;
    }

    int& ret = dp[left][right];
    if (ret != EMPTY)
    {
        return ret;
    }

    // 내 최종 점수 차이 = 현재 점수 - 상대방이 얻는 최적의 점수차
    // 숫자를 가져가는 경우
    ret = max(
        numbers[left] - PlayGame(left + 1, right),
        numbers[right] - PlayGame(left, right - 1)
    );

    // 숫자를 없애는 경우
    if (right - left + 1 >= 2)
    {
        ret = max(ret, -PlayGame(left + 2, right));
        ret = max(ret, -PlayGame(left, right - 2));
    }

    return ret;
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
        numbers.assign(n, 0);
        dp.assign(n, vector<int>(n, EMPTY));

        for (int& num : numbers)
        {
            cin >> num;
        }

        cout << PlayGame(0, n - 1) << "\n";
    }
}
