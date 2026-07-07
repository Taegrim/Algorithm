#include <iostream>

#include <vector>

using namespace std;

// i번 도시 : 금 g{i}, 은 s{i}, 편도 시간 t{i}, 최대 운반 w{i}

// 여러 도시에서 동시에 운반 가능

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;

    int n = g.size();

    long long left = 1;
    long long right = 1e16;

    while (left <= right)
    {
        long long current = (right - left) / 2 + left;

        // 총 금괴, 총 은괴, 모든 광물의 무게
        long long gold = 0;
        long long silver = 0;
        long long total = 0;

        for (int i = 0; i < n; ++i)
        {
            long long time = t[i];
            long long weight = w[i];

            // 현재 시간동안 i도시에선 몇번 운반 가능한지
            // 몇번 왕복 가능한지 검사하고, 남은 시간이 편도 시간 이상이면 횟수 증가
            long long count = current / (time * 2LL);
            if (current % (time * 2LL) >= time)
            {
                ++count;
            }

            // i 도시에서 운반 가능한 최대 무게
            long long max_weight = count * weight;

            gold += min((long long)g[i], max_weight);
            silver += min((long long)s[i], max_weight);
            total += min((long long)g[i] + (long long)s[i], max_weight);
        }

        // 금괴, 은괴, 광물의 합이 요구한대로 올 수 있는지 확인해서 구간 설정
        if (gold >= a && silver >= b && total >= a + b)
        {
            answer = current;
            right = current - 1;
        }
        else
        {
            left = current + 1;
        }
    }

    return answer;
}

int main()
{
    solution(10, 10, { 100 }, { 100 }, { 7 }, { 10 });
    solution(90, 500, { 70, 70, 0 }, { 0, 0, 500 }, { 100, 100, 2 }, { 4, 8, 1 });
}
