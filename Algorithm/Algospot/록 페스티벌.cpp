#include <iostream>
#include <numeric>
#include <vector>
#include <iomanip>

using namespace std;

// 하루 한팀 밴드가 공연
// L팀은 섭외, L일 이상 진행
// 공연장 하루 빌리는 비용 매일ㄷ ㅏ름

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    while (c--)
    {
        // 대여할 수 있는 날들의 수, 공연 팀 수
        int n, l;
        cin >> n >> l;

        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        double cost = numeric_limits<double>::max();

        // 길이만큼 슬라이딩 윈도우
        for (int len = l; len <= n; ++len)
        {
            long long sum = 0;

            // 처음 len 만큼 길이 설정
            for(int i = 0; i < len; ++i)
            {
                sum += v[i];
            }
            cost = min(cost, (double)sum / len);

            // 슬라이딩 윈도우
            for (int i = len; i < n; ++i)
            {
                sum -= v[i - len]; // 맨앞 빼기
                sum += v[i];       // 맨뒤 넣기

                cost = min(cost, (double)sum / len);
            }
        }

        cout << fixed << setprecision(10) << cost << '\n';
    }
}
