#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int answer;

int Func(int left, int right)
{
    if (left == right)
    {
        return v[left];
    }

    int mid = left + (right - left) / 2;

    // 왼쪽 구간, 오른쪽 구간중 가장 큰 값 찾기
    int ret = max(Func(left, mid), Func(mid + 1, right));

    // 중앙에 걸치는 구간에서 찾기
    // 좌우로 확장하면서 최대 크기 구함
    int low = mid;
    int high = mid + 1;

    int min_height = min(v[low], v[high]);

    ret = max(ret, min_height * 2);

    while (left < low || high < right)
    {
        // 오른쪽으로 확장할 수 있고
        // 왼쪽끝에 도달했거나 오른쪽 판자가 더 높다면
        if (high < right
            && (low == left || v[low - 1] < v[high + 1]))
        {
            ++high;
            min_height = min(min_height, v[high]);
        }
        else
        {
            --low;
            min_height = min(min_height, v[low]);
        }

        int width = high - low + 1;
        ret = max(ret, min_height * width);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int loop;
    cin >> loop;

    while (loop--)
    {
        int n;
        cin >> n;

        answer = 0;

        v.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        cout << Func(0, n - 1) << "\n";
    }
}
