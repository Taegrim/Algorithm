#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> ret;

int n;
int MAX_COUNT = 6;

void DFS(int current)
{
    if (ret.size() == MAX_COUNT)
    {
        for (int num : ret)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    for (int i = current; i < n; ++i)
    {
        ret.push_back(v[i]);
        DFS(i + 1);
        ret.pop_back();
    }
}

int main()
{
    int num = 0;

    while (true)
    {
        cin >> n;
        if (n == 0) break;

        v.assign(n, 0);
        ret.clear();

        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        DFS(0);
    }
}
