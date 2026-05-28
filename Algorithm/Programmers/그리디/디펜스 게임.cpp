#include <iostream>

#include <vector>
#include <queue>

using namespace std;

// 병사n, 매 라운드 enemy[i] 마리
// k 번의 무적권으로 enemy[i] 만큼의 소모 막을수 있음

int solution(int n, int k, vector<int> enemy) {

    // 여태까지 진행한 웨이브들을 적이 많은 순서대로 저장하는 큐
    priority_queue<int> pq;

    int current_wave = 0;
    for (; current_wave < enemy.size(); ++current_wave) {
        // 일단 병사 수 감소, 우선순위 큐에 저장
        n -= enemy[current_wave];
        pq.push(enemy[current_wave]);

        // 라운드 종료 위기인데 무적권이 남아있다면
        // 무적권을 사용해서 가장 많았던 웨이브를 회복함
        if (n < 0) {
            if (k <= 0) {
                break;
            }

            n += pq.top();
            pq.pop();
            --k;
        }
    }

    return current_wave;
}

int main()
{
    solution(7, 3, { 4,2,4,5,3,3,1 });
    solution(2, 4, { 3,3,3,3 });
}
