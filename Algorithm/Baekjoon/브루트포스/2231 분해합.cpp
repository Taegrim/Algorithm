#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int base = n;
    int digit = 0;
    while (base > 0)
    {
        ++digit;
        base /= 10;
    }

    // 자릿수 * 9 를 뺀 수부터 시작
    int start = max(1, n - digit * 9);

    int ret = 0;
    for (int i = start; i <= n; ++i)
    {
        long long sum = i;
        long long number = i;

        while (number > 0)
        {
            sum += number % 10;
            number /= 10;
        }

        if (sum == n)
        {
            ret = i;
            break;
        }
    }
    cout << ret << "\n";
}
