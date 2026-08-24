#include <iostream>
#include <vector>

using namespace std;

int n, k, m, l;
// n : 전공과목의 수
// k : 들어야할 과목의 수
// m : 학기의 수
// l : 한 학기에 최대 들을 수 있는 수

vector<int> R;  // R[i] : i를 듣기위해 필요한 선수과목
vector<int> C;  // C[i] : i 학기에 개설되는 과목들
vector<vector<int>> dp;
// dp[term][subject] : 현재 학기가 term, 이고 subject를 들었을 때
//                     앞으로 다녀야하는 최소 학기

constexpr int MAX = 1e9;

// 들은 과목수를 반환하는 함수
int GetCount(int num)
{
    int count = 0;

    // 0이 될때까지 켜져있는 것중 가장 작은 비트 끄기 반복 
    while (num)
    {
        num &= (num - 1);
        ++count;
    }

    return count;
}

// 현재 학기, 현재 수강한 과목들
int Graduation(int term, int subject)
{
    // 이미 k개를 들었다면 종료
    if (GetCount(subject) >= k)
    {
        return 0;
    }

    // 더 이상 남은 학기가 없다면 불가능
    if (term >= m)
    {
        return MAX;
    }

    int& ret = dp[term][subject];
    if (ret != -1)
    {
        return ret;
    }

    ret = MAX;

    // 들을 수 있는 과목 중 듣지 않은 과목 찾아내기
    int can_take = (C[term] & ~subject);

    // 선수과목을 듣지 않은 과목 전부 걸러내기
    for (int i = 0; i < n; ++i)
    {
        // 들을 수 있는 과목에 포함되어있고
        // &연산이 다르다면 (안 들은 것이 있다면)
        if ((can_take & (1 << i)) && (subject & R[i]) != R[i])
        {
            // 해당 비트 지우기
            can_take &= ~(1 << i);
        }
    }

    // 휴학한 경우
    ret = min(ret, Graduation(term + 1, subject));

    // 모든 부분집합 순회
    for (int subset = can_take; subset; subset = ((subset - 1) & can_take))
    {
        // l개 이하만 들을 수 있음
        if (GetCount(subset) > l) continue;

        ret = min(ret, Graduation(term + 1, subject | subset) + 1);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k >> m >> l;

        R.assign(n, 0);
        C.assign(m, 0);
        dp.assign(m, vector<int>(1 << n, -1));

        // R[i]
        // n줄에 선수과목 개수와 번호
        for (int i = 0; i < n; ++i)
        {
            int count;
            cin >> count;

            for (int j = 0; j < count; ++j)
            {
                int num;
                cin >> num;

                R[i] |= (1 << num);
            }
        }

        // m줄에 각학기의 정보, C[i]
        // 해당 학기에 개설되는 과목 개수, 개설되는 과목 번호
        for (int i = 0; i < m; ++i)
        {
            int count;
            cin >> count;

            for (int j = 0; j < count; ++j)
            {
                int num;
                cin >> num;

                C[i] |= (1 << num);
            }
        }

        int ret = Graduation(0, 0);
        if (ret == MAX)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << ret << "\n";
    }
}
