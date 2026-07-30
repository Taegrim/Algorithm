#include <iostream>

using namespace std;

// for문
long long Fib1(int n)
{
    long long dp1[46]{0, };

    dp1[0] = 0;
    dp1[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp1[i] = dp1[i - 2] + dp1[i - 1];
    }

    return dp1[n];
}

// 재귀 풀이
long long dp2[46]{};
long long Fib2(int n)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp2[n] != 0)
    {
        return dp2[n];
    }

    dp2[n] = Fib2(n - 2) + Fib2(n - 1);

    return dp2[n];
}

int main()
{
    int n;
    cin >> n;

    cout << Fib1(n) << "\n";
    cout << Fib2(n) << "\n";
}
