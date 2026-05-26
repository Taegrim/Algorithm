#include <iostream>

#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1{}, sum2{};
    queue<int> q1, q2;

    // 두 큐의 총 합 구하고 나누기
    for (int i : queue1) {
        sum1 += i;
        q1.push(i);
    }
    for (int i : queue2) {
        sum2 += i;
        q2.push(i);
    }

    // 총 합이 홀수면 불가능하므로 -1
    if ((sum1 + sum2) % 2 == 1) {
        return -1;
    }

    // 무한으로 돌지 않게 loop 최대횟수 걸어두기
    int answer = 0;
    int limit = (queue1.size() + queue2.size()) * 2;

    // 큰쪽에서 작은쪽으로 넘기기
    // 넘기려할 때 비어있다면 -1
    while (answer <= limit) {
        if (sum1 == sum2) {
            return answer;
        }

        if (sum1 > sum2) {
            if (q1.empty()) {
                return -1;
            }

            int num = q1.front();
            q2.push(num);
            q1.pop();

            sum1 -= num;
            sum2 += num;
        }
        else {
            if (q2.empty()) {
                return -1;
            }

            int num = q2.front();
            q1.push(num);;
            q2.pop();

            sum2 -= num;
            sum1 += num;
        }
        ++answer;
    }

    return -1;
}

int main()
{
    solution({ 3,2,7,2 }, { 4,6,5,1 });
    solution({ 1,2,1,2, }, { 1,10,1,2 });
    solution({ 1, 1 }, { 1, 5 });
}
