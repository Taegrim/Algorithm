#include <iostream>
#include <vector>

using namespace std;


long long dp[34][34]{};

long long Func(long long one, long long half)
{
    if (one < 0 || half < 0)
    {
        return 0;
    }

    // 모두 다먹으면 횟수 1
    if (one == 0 && half == 0)
    {
        return 1;
    }

    long long& ret = dp[one][half];
    if (ret != -1)
    {
        return dp[one][half];
    }

    ret = 0;    // dp를 -1로 초기화했으니 0으로 한번 초기화해야함

    ret += Func(one - 1, half + 1) + Func(one, half - 1);

    return ret;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        fill(&dp[0][0], &dp[0][0] + 34 * 34, -1);
        

        cout << Func(n, 0) << "\n";
    }
}
