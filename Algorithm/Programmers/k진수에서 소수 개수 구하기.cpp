#include <iostream>


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// n -> k진수 변환
// 1. 소수 양쪽에 0
// 2. 소수 오른쪽에 0, 왼쪽엔 X
// 3. 소수 왼쪽에 0, 오른쪽에 X 
// 4. 양쪽에 X
// 
// !! 자릿수에 0은 포함할 수 없음 !!
//  -> 0을 만났을때만 체크하면 될 것

bool IsPrime(long long n)
{
    // 1 체크, 2,3은 소수, 2,3의 배수는 미리 제거
    if (n < 2) {
        return false; 
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    // 6k-1 과 6k+1 을 한번에 체크
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;

    // k 진수로 변환
    string num{};
    while (n > 0) {
        num += char('0' + (n % k));
        n /= k;
    }
    reverse(num.begin(), num.end());

    // 앞에서부터 0을 만날때까지 확인
    string sub{};
    for (char c : num) {
        // 0을 만나면
        if (c == '0') {

            // 기존까지를 부분 문자열로 보고 해당 문자열 소수 검사
            if (!sub.empty()) {
                long long number = stoll(sub);
                if (IsPrime(number)) {
                    ++answer;
                }
            }

            sub.clear();
        }
        else {
            sub += c;
        }
    }

    // 문자열 종료시 남은 부분 체크
    if (!sub.empty()) {
        long long number = stoll(sub);
        if (IsPrime(number)) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    solution(437674, 3);
    solution(110011, 10);
}


// --------------- 실패한 풀이 -------------------

//// 소수 검사 내용 저장 컨테이너, 0과 1은 false
//vector<bool> is_prime(2, false); 
//
//bool IsPrime(long long n)
//{
//    if (n < 2) return false;
//
//    // size 는 n + 1 이므로 -1 해서 검사
//    // 소수가 기존에 검사했다면 기존 내용을 그대로 사용함
//    if (is_prime.size() - 1 >= n) {
//        return is_prime[n];
//    }
//
//    // 소수가 기존까지 검사한 수보다 크면 다시 검사
//    // 컨테이너를 늘리고 늘린 곳은 true로
//    is_prime.resize(n + 1, true);
//
//    for (long long i = 2; i * i <= n; ++i) {
//
//        // 소수라면 배수들을 false로 변경
//        if (is_prime[i]) {
//            for (long long j = i * i; j <= n; j += i) {
//                is_prime[j] = false;
//            }
//        }
//    }
//
//    return is_prime[n];
//}
