#include <iostream>

#include <vector>

using namespace std;

// 999
// 982
// 182
// 285

// 753762

// 1의 자리부터 자리수별로 확인해서 5 아래면 -, 6 이상이면 + 로 처리
// +로 처리했다면 기존 숫자에 올라간 만큼을 더함

// 5의 경우 앞의 숫자를 보고 유리한걸 선택

int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int num = storey % 10;
        storey /= 10;

        int cost = 0;

        if (num < 5) {
            cost = num;
        }
        else if (num == 5) {
            // 비용은 똑같으나 앞의 숫자에 따라 올라가는지, 내려가는지 선택해야 함
            cost = num;

            // 앞의 숫자가 5 이상이면 올리는게 유리
            if (storey % 10 >= 5) {
                ++storey;
            }
        }
        else {
            cost = 10 - num;
            ++storey;
        }

        answer += cost;
    }

    return answer;
}

int main()
{
    solution(16);
    solution(2554);
    solution(999);
    solution(182);
    solution(982);
}
