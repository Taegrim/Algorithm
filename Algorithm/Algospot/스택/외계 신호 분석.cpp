#include <iostream>
#include <queue>

using namespace std;

int k, n;
// k : 부분 수열의 합
// n : 신호 개수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> k >> n;

        unsigned seed = 1983;
        int count = 0;
        int sum = 0;

        queue<int> q;

        for (int i = 0; i < n; ++i)
        {
            // 현재 시드로 입력 신호 생성
            int signal = seed % 10000 + 1;

            q.push(signal);
            sum += signal;

            seed = seed * 214013u + 2531011u;

            // 합이 크면 왼쪽을 줄임, front를 뽑음
            while (sum > k)
            {
                sum -= q.front();
                q.pop();
            }

            if (sum == k)
            {
                ++count;
            }
        }

        cout << count << "\n";
    }
}
