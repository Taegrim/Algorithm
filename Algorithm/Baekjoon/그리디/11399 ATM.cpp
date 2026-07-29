#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int sum = 0;
    int waiting = 0;

    for (int i = 0; i < n; ++i)
    {
        waiting += v[i];
        sum += waiting;
    }

    cout << sum << "\n";
}
