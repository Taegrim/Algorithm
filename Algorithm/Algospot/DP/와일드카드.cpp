#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

string wildcard, str;

// wildcard[w] 가 str[s] 에 대응되는지 확인
bool IsEqual(int w, int s)
{
    int& ret = dp[w][s];
    if (ret != -1)
    {
        return ret;
    }

    while (s < str.size() && w < wildcard.size()
        && (wildcard[w] == '?' || wildcard[w] == str[s]))
    {
        return ret = IsEqual(w + 1, s + 1);
    }

    // w가 먼저 끝남
    if (w == wildcard.size())
    {
        return ret = (s == str.size());
    }

    // wildcard[w] 가 *였다면
    if (wildcard[w] == '*')
    {
        // 0개의 글자와 대응되는 경우, 1개 이상의 글자와 대응되는 경우
        if (IsEqual(w + 1, s) || (s < str.size() && IsEqual(w, s + 1)))
        {
            return ret = 1;
        }
    }
    
    return ret = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int loop;
    cin >> loop;

    while (loop--)
    {
        // 대소문자, 숫자, *, ?
        cin >> wildcard;

        int n;
        cin >> n;
        vector<string> answer;
        
        for (int i = 0; i < n; ++i)
        {
            cin >> str;
            dp.assign(101, vector<int>(101, -1));

            if (IsEqual(0, 0))
            {
                answer.push_back(str);
            }
        }

        sort(answer.begin(), answer.end());
        for (const string& s : answer)
        {
            cout << s << "\n";
        }
    }
}
