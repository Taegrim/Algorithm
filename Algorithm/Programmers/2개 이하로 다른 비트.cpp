#include <iostream>

#include <vector>

using namespace std;

// 짝수면 +1이 정답
// 홀수라면?

// 3 = 0011 -> 0101 : 5
// 5 = 0101 -> 0110 : 6
// 7 = 0111 -> 1011 : 11
// 9 = 1001 -> 1010 : 10
// 11 = 1011 -> 1101 : 13
//  바뀌는건 오른쪽에서 가까운 0
//  오른쪽이랑 가까운 0 뒤의 수를 더하면 됨
// 
//     1011
//   + 0010
//   -------
//     1101

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long num : numbers) {
        if (num % 2 == 0) {
            answer.push_back(num + 1);
        }
        else {
            long long bit = 1;
            // and 연산 시 0이라면 0 발견
            while ((bit & num) != 0) {
                bit <<= 1;
            }

            // 0 뒤의 수를 더함
            answer.push_back(num + (bit >> 1));
        }
    }

    return answer;
}

int main()
{
    solution({ 2,7 });
}
