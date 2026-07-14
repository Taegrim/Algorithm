#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void DFS(int current)
{
    if (v.size() >= m)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = current; i <= n; ++i)
    {
        v.push_back(i);
        DFS(i + 1);
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    DFS(1);
}
