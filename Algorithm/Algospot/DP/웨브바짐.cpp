#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// e는 지금계란가격, 계란 가격은 m의 배수
string e, digits;   // digits는 e의 자릿수들을 정렬한것
int n, m;

// dp[visited][mod][less]
// visited : 사용한 숫자 집합 (비트연산)
// mod     : 지금까지 만든수를 m으로 나눈 나머지
// less    : 지금까지 만든수가 앞에서부터 비교했을때 e보다 이미 작은지
vector<vector<vector<int>>> dp;

constexpr int MOD = 1000000007;


// 이번에 채울 자리 인덱스, 사용한 자릿수들,
// 지금까지 만든 가격의 m에 대한 나머지, 지금까지 만든 가격이 이미 작으면 1 / 동일하면 0
int GetPrice(int index, int visited, int mod, int less)
{
    if (index == n)
    {
        return (less && mod == 0) ? 1 : 0;
    }

    int& ret = dp[visited][mod][less];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;
    for (int next = 0; next < n; ++next)
    {
        // 방문하지 않았다면
        if ((visited & (1 << next)) == 0)
        {
            // 과거 가격이 지금 가격보다 크면 넘김
            if (!less && e[index] < digits[next])
            {
                continue;
            }

            // 같은 숫자는 한번만 선택하도록
            // 이전숫자와 지금 숫자가 동일한데, 이전숫자를 사용하지 않았다면
            // 중복이 될 수 있으므로 사용 X
            if (next > 0 && digits[next - 1] == digits[next] && (visited & (1 << (next - 1))) == 0)
            {
                continue;
            }

            int next_visited = visited | (1 << next);
            int next_mod = (mod * 10 + digits[next] - '0') % m;
            int next_less = less || (e[index] > digits[next]);
            ret += GetPrice(index + 1, next_visited, next_mod, next_less);
            ret %= MOD;
        }
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
        cin >> e >> m;

        n = e.size();
        digits = e;
        sort(digits.begin(), digits.end());

        dp.assign(1 << n, vector<vector<int>>(m, vector<int>(2, -1)));

        cout << GetPrice(0, 0, 0, 0) << "\n";
    }
}
