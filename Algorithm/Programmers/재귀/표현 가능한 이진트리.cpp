#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이진수 저장하는 빈 문자열 생성
// 이진트리에 더미노드 추가해서 포화 이진트리로 변경, 루트노드는 유지
// 포화 이진트리를 중위탐색
// 더미노드라면 문자열 뒤에 0추가, 아니라면 1추가
// 이진수를 십진수로 변환

// 특정 숫자를 위의 공식을 이용해서 변환 가능한지?

long long GetFullLength(long long n)
{
    long long len = 1;
    while (len < n) {
        len = len * 2 + 1;
    }
    return len;
}

bool CheckParentNode(const string& s, long long left, long long right, bool parent)
{
    if (left > right) {
        return true;
    }

    long long mid = (right - left) / 2 + left;

    // 현재 노드가 1인지 확인
    bool current = (s[mid] == '1');

    // 부모노드가 0인데 현재 노드가 1이면 불가능한 경우
    if (!parent && current) {
        return false;
    }

    // 왼쪽 체크
    if (!CheckParentNode(s, left, mid - 1, current)) {
        return false;
    }

    // 오른쪽 체크
    if (!CheckParentNode(s, mid + 1, right, current)) {
        return false;
    }

    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    answer.reserve(numbers.size());

    for (long long num : numbers) {
        string s = "";
        s.reserve(10000);

        // 이진수로 변환
        while (num > 0) {
            s += num % 2 == 0 ? "0" : "1";
            num /= 2;
        }
        reverse(s.begin(), s.end());

        // 실제 크기와 포화 상태일때 길이 구하기
        long long size = s.size();
        long long len = GetFullLength(size);

        // 포화상태로 만들기 위해 앞에다 0붙이기
        s = string(len - size, '0') + s;

        // 부모노드의 위치 확인하기
        if (CheckParentNode(s, 0, s.size() - 1, true)) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }

    return answer;
}

int main()
{
    solution({ 7,42,5 });
    solution({ 63,111,95 });
}
