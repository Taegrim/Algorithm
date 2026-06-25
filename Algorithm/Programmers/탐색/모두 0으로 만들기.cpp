#include <iostream>

#include <vector>
#include <cmath>

using namespace std;

// 한쪽은 1 증가, 한쪽은 1감소
//  -> +합과 -합이 같아야 모두 0으로 만들 수 있음

//  그래프의 형태는 트리
//   -> 한쪽 방향으로 몰아주기?

vector<vector<int>> graph;
vector<long long> weight;
long long answer = 0;

void DFS(int current, int parent)
{
    for (int next : graph[current])
    {
        if (next == parent) continue;

        DFS(next, current);
    }

    if (parent == -1)
    {
        return;
    }

    // 자식이 없거나 순회가 끝나면 가중치 처리를 시작함
    answer += abs(weight[current]);
    weight[parent] += weight[current];
    weight[current] = 0;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    int n = a.size();

    long long sum = 0;

    weight.reserve(n);
    for (long long num : a)
    {
        sum += num;
        weight.push_back(num);
    }
    if (sum != 0)
    {
        return -1;
    }

    graph.assign(n, vector<int>());
    for (const auto& edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // 0번을 루트로 보고 양쪽 트리에서 0으로 모으기
    DFS(0, -1);

    return answer;
}

int main()
{
    solution({-5, 0, 2, 1, 2}, {{0, 1}, {3, 4}, {2, 3}, {0, 3}} );
    solution({0, 1, 0}, {{0, 1}, {1, 2}} );
}
