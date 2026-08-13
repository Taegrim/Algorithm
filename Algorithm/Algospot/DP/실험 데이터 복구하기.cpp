#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

constexpr int MAX_N = 15;
int n;
string word[MAX_N];
int dp[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];


int GetOverlap(const string& a, const string& b)
{
    int max_len = min(a.size(), b.size());

    for (int len = max_len; len > 0; --len)
    {
        bool same = true;

        for (int i = 0; i < len; ++i)
        {
            if (a[a.size() - len + i] != b[i])
            {
                same = false;
                break;
            }
        }

        if (same)
        {
            return len;
        }
    }

    return 0;
}

void PreCalc()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                overlap[i][j] = GetOverlap(word[i], word[j]);
            }
        }
    }
}

// 마지막에 붙인 문자열, 사용한 문자열이 주어질때
// 앞으로 구할 수 있는 최대 겹침 길이
int Restore(int last, int used)
{
    // 전부 탐색함
    if (used == (1 << n) - 1)
    {
        return 0;
    }

    int& ret = dp[last][used];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;
    for (int next = 0; next < n; ++next)
    {
        if (used & (1 << next))
        {
            continue;
        }

        ret = max(ret, overlap[last][next] + Restore(next, used | (1 << next)));
    }
    return ret;
}

string GetStr(int last, int used)
{
    // 모두 사용했다면 종료
    if (used == (1 << n) - 1)
    {
        return "";
    }

    for (int next = 0; next < n; ++next)
    {
        if (used & (1 << next))
        {
            continue;
        }

        // next를 사용했을때 가장 많이 겹치는 경우라면 사용함
        if (Restore(last, used) == overlap[last][next] + Restore(next, used | (1 << next)))
        {
            return word[next].substr(overlap[last][next])
                + GetStr(next, used | (1 << next));
        }
    }

    return "";
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

        memset(dp, -1, sizeof(dp));
        memset(overlap, 0, sizeof(overlap));

        for (int i = 0; i < n; ++i)
        {
            cin >> word[i];
        }

        // 같은 문자열, 포함되는 문자열 제거
        {
            vector<string> temp;

            for (int i = 0; i < n; ++i)
            {
                bool contained = false;

                for (int j = 0; j < n; ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }

                    if (word[j].find(word[i]) != string::npos)
                    {
                        if (word[j].size() > word[i].size() || j < i)
                        {
                            contained = true;
                            break;
                        }
                    }
                }

                if (!contained)
                {
                    temp.push_back(word[i]);
                }
            }

            n = temp.size();

            for (int i = 0; i < n; ++i)
            {
                word[i] = temp[i];
            }
        }

        PreCalc();

        int best = -1;
        int start = -1;

        for (int i = 0; i < n; ++i)
        {
            int len = Restore(i, 1 << i);

            if (len > best)
            {
                best = len;
                start = i;
            }
        }

        cout << word[start];
        cout << GetStr(start, 1 << start) << "\n";
    }
}
