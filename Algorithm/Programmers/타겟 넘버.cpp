#include <iostream>

#include <vector>

using namespace std;

// 숫자들을 더하고 빼서 target이 되는 경우의 수 
// 숫자의 순서는 바뀌지 않음
// -의 개수, 위치만 바뀜

// -부호만 변경하면서 target이 되는지 체크

void dfs(const vector<int>& numbers, int idx, int sum, int target, int& answer)
{
    // 재귀함수 끝 처리
    if (idx == numbers.size()) {
        if (sum == target) {
            ++answer;
        }
        return;
    }

    // 양수로 계산하고 다음으로 넘어감
    dfs(numbers, idx + 1, sum + numbers[idx], target, answer);

    // 음수로 계산하고 다음으로 넘어감
    dfs(numbers, idx + 1, sum - numbers[idx], target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, 0, 0, target, answer);

    return answer;
}

int main()
{
    solution({ 1,1,1,1,1 }, 3);
    solution({ 4,1,2,1 }, 4);
}
