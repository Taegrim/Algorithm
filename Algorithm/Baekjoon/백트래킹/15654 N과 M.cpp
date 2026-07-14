#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> v;
vector<int> ret;
vector<int> visited;

void DFS()
{
    if (ret.size() >= m)
    {
        for (int i : ret)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i]) continue;

        visited[i] = true;
        ret.push_back(v[i]);
        DFS();
        visited[i] = false;
        ret.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    v.assign(n, 0);
    visited.assign(n, false);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    DFS();
}
