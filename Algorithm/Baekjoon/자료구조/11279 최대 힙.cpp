#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> pq;

    int num = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;

        if (num == 0)
        {
            if (pq.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }
}
