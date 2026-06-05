#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// begin -> target 으로 단어 변경
// 한번에 알파벳 하나만 가능, words에 있는 단어로만 변환 가능

vector<bool> visited;
int answer = 1e9;

int CountDiff(const string& a, const string& b)
{
    int count = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            ++count;
        }
    }
    return count;
}

void DFS(const vector<string>& words, const string& begin, const string& target, int depth)
{
    if (begin == target) {
        answer = min(answer, depth);
        return;
    }

    for (int i = 0; i < words.size(); ++i) {
        // 방문하지 않았고, 알파벳 차이가 1개라면 변환 시도
        if (!visited[i] && CountDiff(begin, words[i]) == 1) {
            visited[i] = true;
            DFS(words, words[i], target, depth + 1);
            visited[i] = false;
        }
    }
}

void BFS(const vector<string>& words, const string& begin, const string& target)
{
    queue<pair<string,int>> q;
    q.push({ begin, 0 });

    while (!q.empty()) {
        auto [str, depth] = q.front();
        q.pop();

        if (str == target) {
            answer = min(answer, depth);
            break;
        }

        for (int i = 0; i < words.size(); ++i) {
            if (!visited[i] && CountDiff(str, words[i]) == 1) {
                visited[i] = true;
                q.push({ words[i],  depth + 1});
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    visited.assign(words.size(), false);

    // words에 target이 있어야 함
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    //DFS(words, begin, target, 0);
    BFS(words, begin, target);

    if (answer == 1e9) {
        return 0;
    }

    return answer;
}

int main()
{
    solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
    solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
}
