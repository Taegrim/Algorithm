#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int answer;
int n, m;

void DFS(int idx, int count, int sum)
{
    if (count == 3)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = idx; i < n; ++i)
    {
        if (sum + v[i] > m) continue;

        DFS(i + 1, count + 1, sum + v[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    v.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    DFS(0, 0, 0);

    cout << answer << "\n";
}
