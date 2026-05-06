#include <iostream>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 연속된 수열의 인덱스 반환
// 합은 k, 짧은 수열, 시작 인덱스 작은수열

vector<int> solution(vector<int> sequence, int k) {
    // 인덱스를 담는 큐
    queue<int> q;
    int sum = 0;

    // 정답이 될 수 있는 후보자 배열
    vector<pair<int, int>> candidate;

    for (int i = 0; i < sequence.size(); ++i) {

        // sum + sequence[i] 비교
        // k를 넘어서면 맨앞에서 계속 제거
        while (!q.empty() &&sum + sequence[i] > k) {
            sum -= sequence[q.front()];
            q.pop();
        }

        q.push(i);
        sum += sequence[i];

        // 연속된 수열 만족한다면 후보자 등록
        if (sum == k) {
            candidate.push_back({ q.front(), q.back() });
        }
    }

    // 후보자에서 짧고 인덱스가 앞인 수열 선택
    sort(candidate.begin(), candidate.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        int len_a = a.second - a.first;
        int len_b = b.second - b.first;

        // 길이가 같다면 인덱스 낮은게 앞으로 오게
        if (len_a == len_b) {
            return a.first < b.first;
        }

        // 길이가 다르면 길이 짧은게 앞으로 오게
        return len_a < len_b;
        });

    return { candidate.front().first, candidate.front().second };
}

int main()
{
    solution({ 1,2,3,4,5 }, 7);
    solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);
    solution({ 2, 2, 2, 2, 2 }, 6);
}
