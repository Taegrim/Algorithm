#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// banned_id 에 해당하는 user_id가 몇명이 있는지
// 일치하는 경우의 수가 몇가지인지

int n;
int answer;
vector<unordered_set<int>> named;

bool IsExist(const unordered_set<int>& us)
{
    for (const auto& names : named) {
        if (names == us) {
            return true;
        }
    }
    return false;
}

void DFS(const vector<vector<int>>& candidates, unordered_set<int> us, int index)
{
    // 모든 후보자 확인했다면
    if (index == n) {
        if (us.size() == n && !IsExist(us)) {
            ++answer;
            named.push_back(us);
        }
        return;
    }

    for (int i : candidates[index]) {
        if (us.count(i)) continue;

        unordered_set<int> next = us;
        next.insert(i);
        DFS(candidates, next, index + 1);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    answer = 0;
    n = banned_id.size();

    vector<vector<int>> candidates(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < user_id.size(); ++j) {
            // 글자수 같은지 확인
            if (banned_id[i].size() == user_id[j].size()) {
                const string& a = banned_id[i];
                const string& b = user_id[j];
                int len = a.size();

                bool equal = true;
                for (int k = 0; k < len; ++k) {
                    if (a[k] != '*' && a[k] != b[k]) {
                        equal = false;
                        break;
                    }
                }
                // 일치한다면 banned_id 의 후보자명단에 user_id의 index를 넣음
                if (equal) {
                    candidates[i].push_back(j);
                }
            }
        }
    }

    DFS(candidates, {}, 0);

    return answer;
}

int main()
{
    solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" });
    solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" });
    solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" });
}
