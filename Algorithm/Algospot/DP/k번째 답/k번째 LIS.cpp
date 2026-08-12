#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> dp_len;
vector<int> dp_count;
int n, k;

constexpr long long MAX = 2000000000;

// idx 뒤로 추가할 수 있는 LIS 개수
int LIS(int idx)
{
    int& ret = dp_len[idx + 1];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;
    for (int next = idx + 1; next < n; ++next)
    {
        if (idx == -1 || v[idx] < v[next])
        {
            ret = max(ret, LIS(next) + 1);
        }
    }

    return ret;
}

// idx 이후로 만들 수 있는 LIS 개수
int Count(int idx)
{
    // LIS 길이가 0이면 1 반환
    // 더이상 선택 불가능하면 LIS 하나 완성된 것
    if (LIS(idx) == 0)
    {
        return 1;
    }

    int& ret = dp_count[idx + 1];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;
    for (int next = idx + 1; next < n; ++next)
    {
        // 현재 LIS가 다음 방문할곳의 LIS + 1 과 같다면
        //  -> 방문할 곳의 LIS가 최대라면
        if ((idx == -1 || v[idx] < v[next])
            && LIS(idx) == LIS(next) + 1)
        {
            ret = min<long long>(MAX, (long long)ret + (long long)Count(next));
        }
    }
    return ret;
}

void ReConstruct(int idx, int skip, vector<int>& lis)
{
    // 시작점은 포함하고 시작
    if (idx != -1)
    {
        lis.push_back(v[idx]);
    }

    // LIS에서 idx의 후보로 next1, next2 가 있을때,
    //  v[next1] < v[next2] 라면 next1은 next2와 연결할 수 있고, next의 LIS를 그대로 사용할 수 있으므로
    //  둘이 같아질 수 없다.
    //  -> 후보가 여러개라면 반드시 v[next1] > v[next2] 여야한다,
    //     즉 내림차순으로 있어야 둘이 같은 길이를 가질 수 있다
    //     따라서 뒤에서부터 확인하면 사전순인걸 확인 가능함

    for (int next = n - 1; next > idx; --next)
    {
        if ((idx == -1 || v[idx] < v[next])
            && LIS(idx) == LIS(next) + 1)
        {
            int count = Count(next);

            if (count <= skip)
            {
                // 이 숫자로 시작하는 LIS 전부 건너뜀
                skip -= count;
            }
            else
            {
                // 다음 숫자가 v[next]라 확정하고 확인
                // 찾는 k번째 LIS가 이 묶음에 있음
                ReConstruct(next, skip, lis);
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        v.assign(n, 0);
        dp_len.assign(n + 1, -1);
        dp_count.assign(n + 1, -1);

        for (int& i : v)
        {
            cin >> i;
        }

        cout << LIS(-1) << "\n";

        vector<int> lis;
        ReConstruct(-1, k - 1, lis);
        for (int i : lis)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}
