#include <iostream>


#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool IsPrime(long long n)
{
    if (n < 2) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    // 6k-1, 6k + 1
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;     // 중복 제거를 위한 set

    // next_permutation 을 위한 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    do {
        string str = "";

        // 뽑아준 순열을 앞에서부터 i개씩 잘라서 set에 넣음
        for (int i = 0; i < numbers.size(); ++i) {
            str += numbers[i];
            s.insert(stoi(str));
        }

    } while (next_permutation(numbers.begin(), numbers.end()));

    for (int num : s) {
        if (IsPrime(num)) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    solution("17");
    solution("011");
}
