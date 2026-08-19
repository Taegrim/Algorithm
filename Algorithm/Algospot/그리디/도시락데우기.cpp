#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> heats(n);
        for (int& num : heats)
        {
            cin >> num;
        }

        vector<int> eats(n);
        for (int& num : eats)
        {
            cin >> num;
        }

        // 먹는 시간, 데우는 시간
        vector<pair<int, int>> lunches(n);
        for (int i = 0; i < n; ++i)
        {
            lunches[i] = { eats[i], heats[i] };
        }

        // 먹는데 오래걸리는 순으로, 같다면 빨리 뎁히는 순으로
        sort(lunches.begin(), lunches.end(),
            [](const pair<int, int>& a, const pair<int, int>& b)
            {
                if (a.first == b.first)
                {
                    return a.second < b.second;
                }
                return a.first > b.first;
            }
        );

        int heat = 0;
        int eat = 0;

        for (int i = 0; i < n; ++i)
        {
            // 뎁히는건 바로바로
            heat += lunches[i].second;

            // 먹는 시간은 뎁히는게 끝난뒤 먹으므로 heat + 먹는시간
            // 이전과 비교해서 오래 걸리는 경우만 남기기
            eat = max(eat, heat + lunches[i].first);
        }

        // 마지막에 먹는게 끝나는게 최종 걸리는 시간
        cout << eat << "\n";
    }
}
