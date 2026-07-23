#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        v[i] = i + 1;
    }

    cout << "<";
    int current = 0;
    while (!v.empty())
    {
        current = (current + k - 1) % v.size();

        cout << v[current];
        v.erase(v.begin() + current);

        if (!v.empty())
        {
            cout << ", ";
        }
    }
    cout << ">";
}
