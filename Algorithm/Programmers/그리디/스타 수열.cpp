#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// x 수열의 길이가 2 이상 짝수
// x의 길이가 2n이면, {x[2n-2], x[2n-1]} 의 교집합의 원소 개수 1 이상
// x[2n-2] != x[2n-1] (n은 자연수)


//int solution(std::vector<int> a) {
//    int n = a.size();
//
//    // 중복된 원소 개수 저장하는 컨테이너
//    // 개수와 인덱스 번호를 저장함
//    unordered_map<int, int> counts;
//    unordered_map<int, vector<int>> indicies;
//
//    for (int i = 0; i < n; ++i)
//    {
//        int num = a[i];
//        ++counts[num];
//        indicies[num].push_back(i);
//    }
//
//    int answer = 0;
//    for (const auto& [num, count] : counts)
//    {
//        const auto& v = indicies[num];
//        unordered_set<int> pairs;
//
//        // 스타수열 될 수 있는지 확인
//        for (int i = 0; i < v.size(); ++i)
//        {
//            // 이전 숫자들중에서 가능한 숫자 하나 선택
//            // 불가능하면 바로 뒤의 숫자 
//            int idx = v[i];
//
//            bool is_find = false;
//            if (idx > 0)
//            {
//                int prev_idx = (i > 0) ? v[i - 1] : -1;
//
//                // 직전 중복 숫자의 인덱스부터 자기자신 전까지 검사
//                for (int j = prev_idx + 1; j < idx; ++j)
//                {
//                    // 숫자가 다르고, 기존에 선택한게 아니라면 스타수열 가능
//                    if (num != a[j] && !pairs.count(j))
//                    {
//                        is_find = true;
//                        pairs.insert(j);
//                        break;
//                    }
//                }
//            }
//
//            // 이전에서 못찾았다면 바로 뒤가 가능한지 검사
//            if (!is_find && idx < a.size() - 1)
//            {
//                int next_idx = idx + 1;
//                if (num != a[next_idx])
//                {
//                    pairs.insert(next_idx);
//                }
//            }
//        }
//
//        answer = max(answer, (int)pairs.size() * 2);
//    }
//
//    return answer;
//}

// 일반 n, n+1 검사 그리디
int solution(std::vector<int> a)
{
    int n = a.size();

    // 중복된 원소 개수 저장하는 컨테이너
    unordered_map<int, int> counts;

    for (int num : a)
    {
        ++counts[num];
    }

    int answer = 0;
    for (const auto& [num, count] : counts)
    {
        // 만들 수 있는 최대 쌍의 개수가 현재 최대값보다 작다면 넘기기
        if (count * 2 <= answer) continue;

        int pair_count = 0;

        for (int i = 0; i < n - 1;)
        {
            if (a[i] != a[i + 1] && (a[i] == num || a[i + 1] == num))
            {
                ++pair_count;
                i += 2;
            }
            else
            {
                ++i;
            }
        }

        answer = max(answer, pair_count * 2);
    }

    return answer;
}

int main()
{
    solution({ 0 });
    solution({ 5,2,3,3,5,3 });
    solution({ 0,3,3,0,7,2,0,2,2,0 });
}
