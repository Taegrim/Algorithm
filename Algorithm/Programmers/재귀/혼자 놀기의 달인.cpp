#include<iostream>

#include <vector>
#include <algorithm>

using namespace std;

// 상자 열고, 숫자카드에 해당하는 번호 상자 열기 반복
// 이미 열려있는 상자라면 끝, 0점, 여태까지 연 상자 수를 그룹화


int solution(vector<int> cards) {
    int answer = 0;
    const int SIZE = cards.size();

    vector<bool> visited(SIZE, false);
    vector<int> groups;

    for (int i = 0; i < SIZE; ++i) {
        if (!visited[i]) {
            int current = i;
            int count = 0;

            // 상자 번호를 따라가면서 열기 반복하고 한 그룹으로 묶음
            while (!visited[current]) {
                visited[current] = true;
                current = cards[current] - 1;
                ++count;
            }
            groups.push_back(count);
        }
    }

    // 그룹화 개수 내림차순 정렬
    sort(groups.begin(), groups.end(), greater<int>());

    if (groups.size() > 1) {
        answer = groups[0] * groups[1];
    }

    return answer;
}

int main()
{
    solution({ 8,6,3,7,2,5,1,4 });
}
