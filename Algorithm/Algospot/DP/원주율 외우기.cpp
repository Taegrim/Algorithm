#include <iostream>
#include <vector>

using namespace std;

// 숫자를 3~5자리로 끊어서 읽으면서 난이도 최소화

vector<int> dp;
string num;

// 시작 index, 난이도를 구할 글자수
int GetLevel(int start, int count)
{
    string str = num.substr(start, count);

    char prev = str[0];
    int prev_diff = str[1] - str[0];

    bool is_equal = true;       // 모든 숫자 같음
    bool is_step = true;        // 등차수열
    bool is_step_one = true;    // 등차 & 단조
    bool is_altenate = true;    // 번갈아

    for (int i = 1; i < count; ++i)
    {
        // 1. 모든 숫자가 같은지
        if (str[i] != prev)
        {
            is_equal = false;
        }

        // 2. 등차수열인지, 차이가 이전과 다르면 등차수열 X
        if (prev_diff != str[i] - prev)
        {
            is_step = false;
        }

        // 3. 등차수열이면서 단조인지
        if (abs(str[i] - prev) != 1)
        {
            is_step_one = false;
        }

        // 4. 번갈아 나오는지, i가 i%2와 다르면 번갈아 X
        if (str[i] != str[i % 2])
        {
            is_altenate = false;
        }

        prev_diff = str[i] - prev;
        prev = str[i];
    }

    if (is_equal)
    {
        return 1;
    }

    if (is_step)
    {
        if (is_step_one)     // 등차면서 단조면
        {
            return 2;
        }

        return 5;   // 등차수열이면
    }

    if (is_altenate)
    {
        return 4;   // 번갈아 나오면
    }

    return 10;
}

int F(int start)
{
    // 문자열의 끝에 도달하면 종료
    if (start == num.size())
    {
        return 0;
    }

    int& ret = dp[start];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1e9;
    for (int count = 3; count <= 5; ++count)
    {
        if (start + count > num.size()) continue;

        ret = min(ret, F(start + count) + GetLevel(start, count));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //cin >> num;
    //cout << GetLevel(0, 4);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> num;
        dp.assign(num.size() + 1, -1);

        cout << F(0) << "\n";
    }
}
