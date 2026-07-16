#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // 시작시간, 끝시간
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    // 끝시간 작은 순으로 정렬
    sort(v.begin(), v.end(), [](const pair<int, int>& a, pair<int, int>& b)
        {
            if (a.second == b.second)
            {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

    int count = 0;
    int last_time = 0;

    for (int i = 0; i < n; ++i)
    {
        // 마지막 회의 종료시간보다 시작시간이 늦다면 가능
        if (last_time <= v[i].first)
        {
            last_time = v[i].second;
            ++count;
        }
    }

    cout << count << "\n";
}
