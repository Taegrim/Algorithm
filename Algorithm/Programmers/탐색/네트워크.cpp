#include <iostream>

#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

bool BFS(const vector<vector<int>>& computers, int start)
{
    if (visited[start]) {
        return false;
    }
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        const auto& computer = computers[current];
        for (int i = 0; i < computer.size(); ++i) {
            if (i == current) continue;

            if (computer[i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    visited.assign(computers.size(), false);

    for (int i = 0; i < computers.size(); ++i) {
        if (BFS(computers, i)) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    solution(3, { {1,1,0}, {1,1,0}, {0,0,1} });
    solution(3, { {1,1,0}, {1,1,1}, {0,1,1} });
}
