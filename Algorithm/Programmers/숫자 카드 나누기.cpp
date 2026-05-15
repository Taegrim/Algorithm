#include <iostream>

#include <string>
#include <vector>
#include <numeric>

using namespace std;

// 철수 숫자 모두 나누기 가능, 영희 숫자는 나눌 수 없음 또는 반대

// 최대 공약수 구하기?

bool CanDivide(const vector<int>& arr, int num)
{
    for (int i : arr) {
        if (i % num == 0) {
            return true;
        }
    }
    return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    int gcd_a = arrayA[0];
    int gcd_b = arrayB[0];
    for (int i = 0; i < arrayA.size(); ++i) {
        gcd_a = std::gcd(gcd_a, arrayA[i]);
        gcd_b = std::gcd(gcd_b, arrayB[i]);
    }

    if (!CanDivide(arrayA, gcd_b)) {
        answer = max(answer, gcd_b);
    }

    if (!CanDivide(arrayB, gcd_a)) {
        answer = max(answer, gcd_a);
    }

    return answer;
}

int main()
{
    solution({ 10, 17 }, { 5,20 });
    solution({ 10, 20 }, { 5,17 });
    solution({ 14, 35, 119 }, { 18, 30, 102 });
}
