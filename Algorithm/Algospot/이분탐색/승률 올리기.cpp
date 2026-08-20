#include <iostream>

using namespace std;

long long n, m;
// n : 플레이 횟수
// m : 승리 횟수

constexpr long long MAX = 200000000LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        int goal = 100 * m / n + 1;

        // 승률이 99퍼거나, 100퍼였다면 1퍼 올리기는 불가능함
        if (goal >= 100)
        {
            cout << -1 << "\n";
            continue;
        }

        long long left = 0;
        long long right = MAX;

        while (left < right)
        {
            long long mid = left + (right - left) / 2;

            long long rate = (m + mid) * 100 / (n + mid);

            if (rate >= goal)
            {
                // 가능하면 구간 줄이기
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }
}
