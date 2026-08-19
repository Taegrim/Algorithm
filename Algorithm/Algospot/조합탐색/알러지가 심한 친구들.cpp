#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
vector<vector<int>> can_eat;    // can_eat[i] = i번째 사람이 먹을 수 있는 음식
vector<vector<int>> eats;   // eats[i] = i번 음식을 먹을 수 있는 친구들

int answer;

// edible[i] : 지금까지 고른 음식 중 i번 친구가 먹을 수 있는 음식 수
// chosen : 지금까지 요리한 음식 수
void Search(vector<int>& edible, int chosen)
{
    // 현재 고른게 기존 최소보다 많거나 같아지면 조기 종료
    if (chosen >= answer)
    {
        return;
    }

    // 음식을 먹을수 없는 친구 찾기
    int idx = 0;
    while (idx < n && edible[idx] > 0)
    {
        ++idx;
    }

    // 모든 친구들이 음식을 먹을 수 있다면 종료
    if (idx == n)
    {
        answer = min(answer, chosen);
        return;
    }

    // 음식을 못먹는 친구가 먹을 수 있는 요리중 하나 요리하기
    for (int food : can_eat[idx])
    {
        // 해당 요리를 먹을수있는 사람 edible 증가
        for (int person : eats[food])
        {
            ++edible[person];
        }

        Search(edible, chosen + 1);

        for (int person : eats[food])
        {
            --edible[person];
        }
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
        cin >> n >> m;

        can_eat.assign(n, vector<int>());
        eats.assign(m, vector<int>());

        answer = 1e9;

        unordered_map<string, int> indices;

        for (int i = 0; i < n; ++i)
        {
            string name;
            cin >> name;

            indices[name] = i;
        }

        for (int i = 0; i < m; ++i)
        {
            int num;
            cin >> num;

            while (num--)
            {
                string name;
                cin >> name;

                int idx = indices[name];

                // idx번째 사람이 i 음식을 먹을 수 있음
                can_eat[idx].push_back(i);

                // i번째 음식을 먹을 수 있는 사람 idx 추가
                eats[i].push_back(idx);
            }
        }

        vector<int> edible(n);
        Search(edible, 0);

        cout << answer << "\n";
    }
}
