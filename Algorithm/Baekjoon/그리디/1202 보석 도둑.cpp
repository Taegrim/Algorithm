#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    // 무게, 가치
    vector<pair<int, int>> v(n);
    vector<int> bags(k);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
  
    for (int i = 0; i < k; ++i)
    {
        cin >> bags[i];
    }
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;

    int item_idx = 0;
    long long total_value = 0;

    for (int capacity : bags)
    {
        while (item_idx < n && v[item_idx].first <= capacity)
        {
            pq.push(v[item_idx].second);
            ++item_idx;
        }

        if (pq.size())
        {
            total_value += pq.top();
            pq.pop();
        }
    }

    cout << total_value << "\n";
}
