#include <iostream>

#include <vector>
#include <limits>
#include <queue>

using namespace std;

// 시간초과 발생
//void dfs(int number, int target, int n, int depth, int& count)
//{
//    // 타겟을 찾았다면 최소 depth 저장
//    if (number == target) {
//        count = min(count, depth);
//        return;
//    }
//    else if (number > target) {
//        return;
//    }
//
//    // 최소 depth가 될 수 없다면 시도 자체를 안하도록 함
//    if (depth < count) {
//        dfs(number + n, target, n, depth + 1, count);
//        dfs(number * 2, target, n, depth + 1, count);
//        dfs(number * 3, target, n, depth + 1, count);
//    }
//}


// -------------------------------------------
// --------------- bfs 풀이 ------------------
int bfs(int number, int target, int n)
{
    vector<int> visited(target + 1, -1);
    queue<int> q;

    q.push(number);
    visited[number] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == target) {
            return visited[x];
        }

        int nexts[]{ x + n, x * 2, x * 3 };

        // 목표보다 작을때만 탐색 루트로 잡기
        // bfs 특성상 방문하지 않은 경우가 최소이므로
        // 방문하지 않았을때만 경로에 넣기
        for (int next : nexts) {
            if (next <= target && visited[next] == -1) {
                visited[next] = visited[x] + 1;
                q.push(next);
            }
        }
    }

    // 못찾으면 -1
    return -1;
}

int solution(int x, int y, int n) {
    return bfs(x, y, n);
}
// -------------------------------------------

// -------------------------------------------
// -------------- dp 풀이 --------------------
//int solution(int x, int y, int n) {
//    constexpr int MAX = numeric_limits<int>::max();
//    vector<int> counts(y + 1, MAX);
//
//    counts[x] = 0;
//
//    for (int i = x; i <= y; ++i) {
//        // 변환으로 나올 수 없는 수라면 건너뜀
//        if (counts[i] == MAX) {
//            continue;
//        }
//
//        // 기존과 비교해서 최소 경로 선택
//        if (i + n <= y) {
//            counts[i + n] = min(counts[i + n], counts[i] + 1);
//        }
//        if (i * 2 <= y) {
//            counts[i * 2] = min(counts[i * 2], counts[i] + 1);
//        }
//        if (i * 3 <= y) {
//            counts[i * 3] = min(counts[i * 3], counts[i] + 1);
//        }
//    }
//
//    if (counts[y] == MAX) {
//        counts[y] = -1;
//    }
//
//    return counts[y];
//}
// -------------------------------------------

int main()
{
    solution(10, 40, 5);
    solution(10, 40, 30);
    solution(2, 5, 4);
}
