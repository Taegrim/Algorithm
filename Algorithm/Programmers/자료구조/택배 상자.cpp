#include <iostream>


#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 큐 순서가 1,2,3,4,5 이므로 만들지 않고 box 라는 int 로 관리
int solution(vector<int> order)
{
    stack<int> other;
    int idx = 0;    // 현재 박스 순서, 적재한 박스 개수

    // 현재 기본 레일의 맨 앞부터 끝까지 loop 돌리기만 함
    // 항상 보조레일에 넣고 보조레일로 검사
    for (int box = 1; box <= order.size(); ++box) {
        other.push(box);

        // 보조 레일에서만 트럭에 적재 수행
        while (!other.empty() && other.top() == order[idx]) {
            other.pop();
            ++idx;
        }
    }

    return idx;
}


// 기존 컨테이너 벨트 = 큐
// 보관용 컨테이너 벨트 = 스택

//// 시뮬레이션
//int solution(vector<int> order) {
//    int answer = 0;
//    queue<int> base;
//    stack<int> other;
//
//    for (int i = 0; i < order.size(); ++i) {
//        base.push(i + 1);
//    }
//
//    int current_idx = 0;
//
//    while (current_idx < order.size()) {
//        int current_order = order[current_idx];
//
//        // 기본 레일 맨 앞이 원하는 상자라면 적재
//        if (!base.empty() && base.front() == current_order) {
//            base.pop();
//            ++current_idx;
//            ++answer;
//        }
//        // 보조 레일 맨 위가 원하는 상자라면 적재
//        else if (!other.empty() && other.top() == current_order) {
//            other.pop();
//            ++current_idx;
//            ++answer;
//        }
//        // 둘 다 아니라면 기본 레일에서 보조 레일로 이동
//        else {
//            // 둘다 원하는 상자가 아니면서 base가 비었다면 빠져나와야 함
//            if (base.empty()) {
//                break;
//            }
//
//            other.push(base.front());
//            base.pop();
//        }
//    }
//
//    return answer;
//}

int main()
{
    solution({ 4,3,1,2,5 });
    solution({ 5,4,3,2,1 });
}
