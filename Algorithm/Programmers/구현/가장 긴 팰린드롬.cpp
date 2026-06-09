#include <iostream>

#include <string>

using namespace std;

// 앞에서부터 지나가면서 확인할 수는 없는지
//  - 앞에서부터 볼때 index - 2 랑 같은 문자면 팰린드롬 가능성
//  - index - 1 이랑같은 문자면 팰린드롬 가능성

int max_length;

void GetLength(const string& s, int left, int right)
{
    int n = s.size();

    // left == right 면 aba 같은 경우, 아니면 abba 같은 경우
    int count = (left == right) ? -1 : 0;

    // 범위 내에서 같다면 계속 탐색
    while (left >= 0 && right < n && s[left] == s[right]) {
        --left;
        ++right;
        count += 2;
    }

    max_length = max(max_length, count);
}

int solution(string s)
{
    max_length = 1;

    for (int i = 0; i < s.size(); ++i) {
        // abba 에서  bb처럼 연달아 같은 문자면 팰린드롬 가능
        if (i >= 1 && s[i - 1] == s[i]) {
            GetLength(s, i - 1, i);
        }
        // aba 에서 i가 두번째 a인 상황, 팰린드롬 가능
        if (i >= 2 && s[i - 2] == s[i]) {
            GetLength(s, i - 1, i - 1);
        }
    }

    return max_length;
}

int main()
{
    solution("abcdcba");
    solution("abacde");
}
