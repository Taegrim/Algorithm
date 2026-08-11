#include <iostream>
#include <vector>

using namespace std;

// <이름, <부피, 절박도>>
vector<pair<string, pair<int, int>>> v;
vector<vector<int>> dp;

int n, w;


// 현재 물건, 남은 용량
int Func(int idx, int remain)
{
    if (idx < 0)
    {
        return 0;
    }

    int weight = v[idx].second.first;
    int value = v[idx].second.second;

    int& ret = dp[idx][remain];
    if (ret != -1)
    {
        return ret;
    }

    // 현재 물건을 담는다 / 안담는다
    // Func(idx - 1) = max(Func(idx - 1, remain - weight) + , Func(idx - 1, remain))

    // 안담고 그대로
    ret = Func(idx - 1, remain);

    // 가능하면 담기
    if (remain >= weight)
    {
        ret = max(ret, Func(idx - 1, remain - weight) + value);
    }

    return ret;
}

void GetString(int idx, int remain, vector<string>& items)
{
    if (idx < 0)
    {
        return;
    }

    // 이전과 같다면 안골랐음
    if (Func(idx, remain) == Func(idx - 1, remain))
    {
        GetString(idx - 1, remain, items);
    }
    else
    {
        items.push_back(v[idx].first);
        GetString(idx - 1, remain - v[idx].second.first, items);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> w;
        v.assign(n, {});
        dp.assign(n + 1, vector<int>(w + 1, -1));

        for (auto& [name, pairs] : v)
        {
            cin >> name >> pairs.first >> pairs.second;
        }

        cout << Func(n - 1, w) << " ";

        vector<string> items;
        GetString(n - 1, w, items);

        cout << items.size() << "\n";
        for (int i = items.size() - 1; i >= 0; --i)
        {
            cout << items[i] << "\n";
        }
    }
}
