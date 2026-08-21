#include <iostream>
#include <vector>

using namespace std;

// 소수 판별 기본
bool IsPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int k = 5; k * k <= n; k += 6)
    {
        if (n % k == 0 || n % (k + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

// 소인수 분해
vector<int> FactorSimple(int n)
{
    vector<int> ret;

    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            n /= i;
            ret.push_back(i);
        }
    }

    if (n > 1)
    {
        ret.push_back(n);
    }

    return ret;
}

// 에라토스테네스의 체
vector<bool> Eratosthenes(int n)
{
    vector<bool> numbers(n + 1, true);

    numbers[0] = numbers[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        // 이 수가 지워지지 않았다면 배수들을 false로 변경
        if (numbers[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                numbers[j] = false;
            }
        }
    }

    return numbers;
}


// min_factor[i] : i의 가장 작은 소인수, i가 소수면 자기자신
int MAX_N;
vector<int> min_factor;

// 에라토스테네스의 체로 소인수 분해 정보 저장
void Eratosthenes2()
{
    min_factor[0] = min_factor[1] = -1;

    // 모든 수에 대해 자기자신으로 설정하고 시작
    for (int i = 2; i <= MAX_N; ++i)
    {
        min_factor[i] = i;
    }

    for (int i = 2; i * i <= MAX_N; ++i)
    {
        if (min_factor[i] == i)
        {
            for (int j = i * i; j <= MAX_N; j += i)
            {
                // 변경하지 않은 경우에만 약수 변경
                if (min_factor[j] = j)
                {
                    min_factor[j] = i;
                }
            }
        }
    }
}

// 에라토스테네스의 체를 이용한 소인수 분해 빠르게 구하기
vector<int> Factor(int n)
{
    vector<int> ret;

    while (n > 1)
    {
        ret.push_back(min_factor[n]);
        n /= min_factor[n];
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MAX_N = 10000;
    min_factor.assign(MAX_N + 1, -1);

    Eratosthenes2();

    for (int i : Factor(9991))
    {
        cout << i << "\n";
    }
}
