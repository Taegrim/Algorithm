#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

// ICN에서 시작해서 모든 경로를 가야함
// 경로가 여러개면 알파벳 순서가 앞인 경우를 반환
// -> 사이클이 반드시 존재함

unordered_map<string, vector<string>> um;
vector<string> path;
vector<string> answer;
int n;

bool DFS(const string& current)
{
    if (path.size() == n) {
        answer = path;
        return true;
    }

    vector<string>& v = um[current];

    for (int i = 0; i < v.size(); ++i) {
        string next = v[i];

        // 사용
        v.erase(v.begin() + i);
        path.push_back(next);

        if (DFS(next)) {
            return true;
        }

        // 복구
        path.pop_back();
        v.insert(v.begin() + i, next);
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size() + 1;

    path.reserve(n);
    answer.reserve(n);

    for (const auto& v : tickets) {
        um[v[0]].push_back(v[1]);
    }

    // 미리 알파벳 낮은 순서대로 정렬해두기
    for (auto& [str, v] : um) {
        sort(v.begin(), v.end());
    }

    path.push_back("ICN");
    DFS(path.front());

    return answer;
}

int main()
{
    solution({ {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} });
    solution({ {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} });
}
