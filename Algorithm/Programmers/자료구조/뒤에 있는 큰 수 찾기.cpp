#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

//// 특정 위치를 검사할 때 이전에 뒷 큰수를 못찾은 것만 체크할 수 있다면?
//
//vector<int> solution(vector<int> numbers) {
//    // numbers 크기만큼 -1로 초기화
//    vector<int> answer(numbers.size(), -1);
//
//    // 인덱스를 넣는 스택
//    stack<int> st;
//
//    for (int i = 0; i < numbers.size(); ++i) {
//        const int& num = numbers[i];
//
//        // 스택이 안비었고
//        // 스택 최상단 인덱스에 해당하는 숫자보다 현재 숫자가 크면 체크
//        while (!st.empty() && numbers[st.top()] < num) {
//            answer[st.top()] = num;
//            st.pop();
//        }
//        // 검사한 인덱스 스택에 넣기
//        st.push(i);
//    }
//
//    return answer;
//}

vector<int> solution(vector<int> numbers) {
    vector<int> answers(numbers.size(), -1);
    stack<int> st;

    // 뒤에서부터 체크
    // 특정 위치의 수가 stack에 있는 값보다 작으면 뒷 큰수로 저장
    for (int i = numbers.size() - 1; i >= 0; --i) {
        const int& num = numbers[i];

        // 만약 현재 위치의 수가 stack의 상단보다 크면 pop
        while (!st.empty() && st.top() <= num) {
            st.pop();
        }

        if (!st.empty()) {
            answers[i] = st.top();
        }

        st.push(num);
    }

    return answers;
}

int main()
{
    solution({ 2,3,3,5 });
    solution({ 9,1,5,3,6,2 });
}
