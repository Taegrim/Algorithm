#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, lo, hi;

int MAX = 10000000;
vector<int> min_factor(MAX + 1);    // min_factor[i] : i의 가장 작은 소인수
vector<int> min_factor_power(MAX + 1); // min_factor_power[i] : i의 소인수 분해엔 min_factor가 몇승이 포함되어있는지
vector<int> factors(MAX + 1); // factos[i] : i가 가진 약수 개수

void Pref()
{
    min_factor[0] = min_factor[1] = -1;

    for (int i = 2; i <= MAX; ++i)
    {
        min_factor[i] = i;
    }

    for (int i = 2; i * i <= MAX; ++i)
    {
        if (min_factor[i] == i)
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                if (min_factor[j] == j)
                {
                    min_factor[j] = i;
                }
            }
        }
    }

    factors[1] = 1;

    for (int i = 2; i <= MAX; ++i)
    {
        // 소수라면
        if (min_factor[i] == i)
        {
            // 자기자신 1승, 약수 2개
            min_factor_power[i] = 1;
            factors[i] = 2;
        }
        else
        {
            // 소수가 아니면 가장 작은 소인수로 나눈 수의 약수를 이용해 i의 약수 개수 찾음
            int p = min_factor[i];
            int remain = i / p;

            // 가장 작은 소인수를 떼어냈을 때 더이상 없다면 1개라고 기록
            if (p != min_factor[remain])
            {
                min_factor_power[i] = 1;
            }
            else
            {
                // 아직 해당 소인수가 남아있다면 나머지 수에 대한 min_factor_power 에서 1을 더함
                min_factor_power[i] = min_factor_power[remain] + 1;
            }

            int a = min_factor_power[i];
            factors[i] = (factors[remain] / a) * (a + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // 전처리
    Pref();

    while (t--)
    {
        cin >> n >> lo >> hi;

        int ret = 0;
        for (int i = lo; i <= hi; ++i)
        {
            if (factors[i] == n)
            {
                ++ret;
            }
        }

        cout << ret << "\n";
    }
}
