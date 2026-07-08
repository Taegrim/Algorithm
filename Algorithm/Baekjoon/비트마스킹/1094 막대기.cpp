#include <iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target;
    cin >> target;

    int count = 0;
    while (target > 0)
    {
        if (target & 1)
        {
            ++count;
        }
        target >>= 1;
    }

    cout << count << "\n";
}
