#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// info = i번 노드에 양 or 늑대 정보
// edges = 간선
// DFS + 갈 수 있는 길을 저장해야할듯

vector<vector<int>> graph;
int answer;

void DFS(const vector<int>& info, unordered_set<int> candidates, int current, int sheep, int wolf)
{
    if (info[current] == 0) {
        ++sheep;
    }
    else {
        ++wolf;
    }

    if (wolf >= sheep) {
        return;
    }

    answer = max(answer, sheep);

    // 현재 노드에서 갈 수 있는 길 후보 등록
    for (int next : graph[current]) {
        candidates.insert(next);
    }

    // 후보자 명단에서 경로 선택
    for (int next : candidates) {
        // 다음 경로를 복사해서 전달함
        // 한 경로로 들어갔을때 다른 경로들이 남아있어야 하기 때문
        unordered_set<int> nexts = candidates;
        nexts.erase(next);

        DFS(info, nexts, next, sheep, wolf);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    answer = 0;
    graph.assign(info.size(), vector<int>());

    for (const auto& v : edges) {
        int parent = v[0];
        int child = v[1];

        graph[parent].push_back(child);
    }

    DFS(info, {}, 0, 0, 0);

    return answer;
}

int main()
{
    solution({ 0,0,1,1,1,0,1,0,1,0,1,1 },
        { {0,1} ,{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9} });
    solution({ 0,1,0,1,1,0,1,0,0,1,0 },
        { {0,1} ,{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,8},{6,9},{9,10} });
}
