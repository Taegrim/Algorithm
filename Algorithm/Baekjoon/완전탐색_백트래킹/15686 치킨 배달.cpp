#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> stores;
vector<pair<int, int>> houses;
vector<int> selected_stores;    // 선택한 가게의 인덱스

int n, m;
int chicken_dist = 1e9;

void CheckDist()
{
    int sum = 0;

    for (const auto& [hr, hc] : houses)
    {
        int min_dist = 1e9;

        for (int idx : selected_stores)
        {
            const auto& [sr, sc] = stores[idx];

            int dist = abs(sr - hr) + abs(sc - hc);
            min_dist = min(min_dist, dist);
        }

        // 모든 집들의 치킨거리 더하기
        sum += min_dist;
    }
    // 도시의 치킨거리 최솟값 확인
    chicken_dist = min(chicken_dist, sum);
}

void DFS(int current)
{
    // 선택한 치킨집들의 치킨거리 구하기
    if (selected_stores.size() == m)
    {
        CheckDist();
        return;
    }

    for (int i = current; i < stores.size(); ++i)
    {
        selected_stores.push_back(i);
        DFS(i + 1);
        selected_stores.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    stores.reserve(13);
    selected_stores.reserve(m);

    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> num;

            if (num == 2)
            {
                // 치킨집 기록
                stores.push_back({ i,j });
            }
            else if (num == 1)
            {
                // 집 기록
                houses.push_back({ i, j });
            }
        }
    }

    DFS(0);

    cout << chicken_dist << "\n";
}
