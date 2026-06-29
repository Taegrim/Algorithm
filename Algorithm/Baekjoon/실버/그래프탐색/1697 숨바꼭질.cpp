#include <iostream>
#include <queue>

using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> visited(100004, 0);

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == m) break;

        int nexts[]{ current - 1, current + 1, current * 2 };
        for (int next : nexts)
        {
            if (next < 0 || next >= visited.size()) continue;
            if (visited[next]) continue;

            q.push(next);
            visited[next] = visited[current] + 1;
        }
    }

    cout << visited[m] - 1 << endl;
}
