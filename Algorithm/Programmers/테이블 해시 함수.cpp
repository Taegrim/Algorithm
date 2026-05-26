#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;


// 튜플을 col번째 컬럼의 값으로 오름차순,
// 동일하면 기본키 첫번째 컬럼 값 기준 내림차순
// -> data 벡터의 col 번째 값으로 오름차순, 동일하면 첫번째 값 기준 내림차순

// 정렬된 데이터에서 S_i를 i번째 행의 튜플에 대해
// 각 컬럼의 값을 i로 나눈 나머지들의 합으로 정의
// row_begin <= i <= row_end 인 모든 S_i를 누적해서 bitwise XOR 한 값을 해시로반환

// -> 1. row_begin 부터 row_end 까지의 행을 탐색
//    2. 행에 있는 값들을 i로 나눈 나머지의 합을 구해서 S_i로 정의
//    3. S_i 들을 전부 XOR 연산함

// col, row 전부 인덱스가 아닌 i번째 숫자로 들어옴, 1 빼야 함

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {

    int col_index = col - 1;

    // col번째 값을 기준으로 오름차순, 같으면 첫번째 값을 기준으로 내림차순
    sort(data.begin(), data.end(), [col_index](const vector<int>& v1, const vector<int>& v2) {
        if (v1[col_index] == v2[col_index]) {
            return v1[0] > v2[0];
        }
        return v1[col_index] < v2[col_index];
        });


    int answer = 0;
    
    // S_i 구하고 XOR 연산
    for (int i = row_begin; i <= row_end; ++i) {
        int row_index = i - 1;
        int sum = 0;

        for (int num : data[row_index]) {
            sum += num % i;
        }

        answer ^= sum;
    }

    return answer;
}

int main()
{
    solution({ { 2,2,6 }, { 1,5,10 }, { 4,2,9 }, { 3,8,3 } }, 2, 2, 3);
}
