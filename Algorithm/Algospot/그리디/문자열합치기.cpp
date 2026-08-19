#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;

            pq.push(num);
        }

        int answer = 0;

        while (pq.size() > 1)
        {
            // 가장 짧은 2개를 합치고 큐에 다시 넣기 반복
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);

            answer += (a + b);
        }

        cout << answer << "\n";
    }
}
