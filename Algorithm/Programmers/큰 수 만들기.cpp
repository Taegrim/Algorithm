#include <iostream>

#include <string>

using namespace std;

// 앞에서부터 스택에 담기
// 스택의 위보다 큰 수를 만나면 스택의 위부터 제거

string solution(string number, int k) {
    string answer = "";

    for (char c : number) {
        // 잘라낼 횟수가 남아있고
        // 조합한 문자열의 뒤에서부터 확인해서 큰 문자를 만나면 제거
        while (!answer.empty() && k > 0 && answer.back() < c) {
            answer.pop_back();
            --k;
        }
        answer.push_back(c);
    }

    // 문자열 완성되고도 잘라낼 횟수가 남았다면 뒤에서 제거
    while (k > 0) {
        answer.pop_back();
        --k;
    }

    return answer;
}

int main()
{
    solution("1924", 2);
    solution("1231234", 2);
    solution("4177252841", 2);
}
