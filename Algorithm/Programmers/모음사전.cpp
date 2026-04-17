#include <iostream>


#include <string>
#include <vector>

using namespace std;

bool dfs(const string& target, string& word, const vector<char>& alpha, int& answer)
{
    // 단어를 찾았다면 빠져나오도록 함
    if (word == target) {
        return true;
    }
    // 그냥 탐색종료라면 false 리턴
    if (word.size() == alpha.size()) {
        return false;
    }

    for (int i = 0; i < alpha.size(); ++i) {
        word += alpha[i];
        ++answer;

        // 하위 탐색에서 찾았다면 올라가면서 true 계속 리턴함
        // 재귀를 끝내는 용도로 if 체크
        if (dfs(target, word, alpha, answer)) {
            return true;
        }

        // dfs 처리해서 못찾았다면 단어 복구
        word.pop_back();
    }
    
    return false;
}

int solution(string word) {
    int answer = 0;

    vector<char> alpha{ 'A', 'E', 'I', 'O', 'U' };
    string s = "";

    dfs(word, s, alpha, answer);

    return answer;
}

int main()
{
    solution("AAAAE");
    solution("AAAE");
    solution("I");
    solution("EIO");
}