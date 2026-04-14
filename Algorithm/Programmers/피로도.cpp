#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

// 최소 피로도 = 입장시 필요한 최소한의 피로도
// 소모 피로도 = 던전 탐색 후 소모하는 피로도
// 최소 피로도 >= 소모피로도

// 현재 피로도 = k
// 던전은 하루 한번 탐색 가능
// 최대 8개로 던전 제한

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int size = dungeons.size();

    vector<int> indicies(size);
    for (int i = 0; i < size; ++i) {
        indicies[i] = i;
    }

    // 순열로 모든 경우의 수를 체크
    do {
        int current_k = k;
        int count = 0;

        for (int i = 0; i < size; ++i) {
            int minimum = dungeons[indicies[i]][0];
            int used = dungeons[indicies[i]][1];

            if (current_k >= minimum) {
                current_k -= used;
                ++count;
            }
        }

        answer = max(answer, count);

    } while (next_permutation(indicies.begin(), indicies.end()));

    return answer;
}

int main()
{
    solution(80, { {80,20}, {50,40}, {30,10} });
}