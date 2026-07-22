#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    deque<int> deq(n);
    for (int i = 1; i <= n; ++i)
    {
        deq[i - 1] = i;
    }

    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;

        // 몇번째 위치에 있는지 찾기
        int idx = -1;
        int size = deq.size();
        for (int j = 0; j < size; ++j)
        {
            if (deq[j] == num)
            {
                idx = j;
                break;
            }
        }

        // 회전
        while (!deq.empty() && deq.front() != num)
        {
            int temp = -1;
            if (idx * 2 + 1 <= size)
            {
                // 왼쪽 회전값 저장
                temp = deq.front();
                deq.pop_front();
                deq.push_back(temp);
            }
            else
            {
                // 오른쪽 회전값 저장
                temp = deq.back();
                deq.pop_back();
                deq.push_front(temp);
            }
            ++count;
        }
        deq.pop_front();
    }

    cout << count << "\n";
}
