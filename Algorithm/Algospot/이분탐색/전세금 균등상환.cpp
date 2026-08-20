#include <iostream>
#include <vector>

using namespace std;

int n, m;
double p;
// n : 대출금액
// m : M개월동안 갚음
// p : 월 (P/12)% 만큼 이자

// c : 한달마다 상환할 금액
double GetRemaining(int n, int m, double p, double c)
{
    double result = n;

    for (int i = 0; i < m; ++i)
    {
        result *= (1.0 + (p / 12.0) / 100.0);
        result -= c;

        if (result <= 0.0)
        {
            break;
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m >> p;

        double left = 0.0;
        double right = n * (1.0 + (p / 12.0) / 100.0);  // 1달만에 전부 갚기

        for (int i = 0; i < 100; ++i)
        {
            double mid = left + (right - left) / 2.0;

            if (GetRemaining(n, m, p, mid) <= 0.0)
            {
                // 갚을 수 있다면 금액 줄이기
                right = mid;
            }
            else
            {
                // 갚을 수 없다면 금액 늘리기
                left = mid;
            }
        }

        cout << fixed;
        cout.precision(10);
        cout << right << "\n";
    }
}
