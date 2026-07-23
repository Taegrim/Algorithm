#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string base("666");

    int count = 1;
    int num = 666;

    while (count < n)
    {
        ++num;

        string s = to_string(num);
        if (s.find("666") != -1)
        {
            ++count;
        }
    }

    cout << num << "\n";
}
