#include <iostream>

#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;

void DFS(int current, int parent)
{
    dp[current][0] = 0; // 현재 등대를 끔
    dp[current][1] = 1; // 현재 등대를 켬

    for (int next : graph[current])
    {
        if (next == parent) continue;

        DFS(next, current);

        // 현재 등대가 꺼져있으면 자식들을 전부 켜야함
        dp[current][0] += dp[next][1];

        // 현재 등대가 켜져있으면 자식들은 킨것, 끈것 중 최솟값 선택
        dp[current][1] += min(dp[next][0], dp[next][1]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    // dp : i번째 등대가 꺼짐(0), 켜짐(1) 일때 서브트리에서 필요한 최소 등대 개수
    //  i번째 등대를 켜면 자식에선 켜도되고, 안켜도 됨
    //  dp[i][1] = 1 + min(dp[child][0], dp[child][1]) ...
    //  dp[i][0] = dp[child][1] ...

    graph.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, 0));

    for (const auto& house : lighthouse)
    {
        graph[house[0]].push_back(house[1]);
        graph[house[1]].push_back(house[0]);
    }

    DFS(1, 1);

    return min(dp[1][0], dp[1][1]);
}

int main()
{
    solution(8, {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {5, 6}, {5, 7}, {5, 8}} );
    solution(10, {{4, 1}, {5, 1}, {5, 6}, {7, 6}, {1, 2}, {1, 3}, {6, 8}, {2, 9}, {9, 10}} );
}
