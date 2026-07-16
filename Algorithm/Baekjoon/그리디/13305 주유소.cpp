#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수평으로 도시 나열
// 처음엔 기름 넣고 출발해야 함
// 1km 마다 1리터 기름, 주유소당 리터 가격이 다름

int main()
{
    int n;
    cin >> n;

    // 마지막 지역 가격은 의미 없음
    vector<long long> length(n-1);
    vector<long long> price(n);

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> length[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> price[i];
    }

    long long sum = price[0] * length[0];
    long long min_price = price[0];

    for (int i = 1; i < n - 1; ++i)
    {
        min_price = min(min_price, price[i]);
        sum += min_price * length[i];
    }

    cout << sum << "\n";

    //long long sum = 0;
    //int current = 0;
    //int target = 0;
    //int len = 0;

    //// 다음 도시 계속 확인
    //// 낮은 주유소 발견하면 거기까지만 충전하고 이동
    //// 아니면 계속 충전하면서 이동한다 생각

    //while (current < n)
    //{
    //    // 마지막 목적지가 끝이라면 즉시 이동
    //    if (target == n - 1)
    //    {
    //        sum += price[current] * len;
    //        break;
    //    }

    //    // 지금 주유소의 비용이 낮다면 길이 저장
    //    if (price[current] <= price[target])
    //    {
    //        len += length[target];
    //        ++target;
    //    }
    //    else
    //    {
    //        // 더 낮은 주유소를 발견하면 이동
    //        sum += price[current] * len;
    //        current = target;
    //        len = 0;
    //    }
    //}

}
