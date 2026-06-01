#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 완전탐색 DFS 기본 상태
/*
void DFS(int index)
{
    if (index == 선택할_개수) {
        현재까지 만든 조합 평가;
        return;
    }

    for (가능한 선택지) {
        현재 index에 선택 저장;
        DFS(index + 1);
    }
}
*/

// 1. 플러스 가입자 최대, 2. 판매액 최대
// N명에게 M개를 할인해서 판매
// 일정 비율 이상 할인은 모두 구매, 구매비용 일정 넘어가면 취소하고 플러스 가입

int max_users = -1;
int max_sales = -1;
vector<int> discounts;

void DFS(const vector<vector<int>>& users, vector<int>& emoticons, int index)
{
    if (index == emoticons.size()) {
        int user_count = 0;
        int total_sales = 0;

        for (const vector<int>& v : users) {
            int rate = v[0];    // 구매할 할인율
            int limit = v[1];   // 플러스 가입 최소 비용
            int prices = 0;     // 총 구매 금액

            // 이모티콘별 할인율 체크
            for (int i = 0; i < discounts.size(); ++i) {
                if (discounts[i] >= rate) {
                    int price = emoticons[i] * (100 - discounts[i]) / 100;
                    prices += price;
                }
            }

            // 구매한도를 넘어서면 모두 취소하고 플러스 가입
            if (prices >= limit) {
                ++user_count;
                prices = 0;
            }
            total_sales += prices;
        }

        // 기존 가입자수보다 많다면 갱신
        if (user_count > max_users) {
            max_users = user_count;
            max_sales = total_sales;
        }
        // 가입자수가 똑같다면 판매비용만 갱신
        else if (user_count == max_users) {
            max_sales = max(max_sales, total_sales);
        }

        return;
    }

    // 할인율 완전탐색
    for (int discount : {10, 20, 30, 40}) {
        discounts[index] = discount;
        DFS(users, emoticons, index + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    discounts.resize(emoticons.size());

    DFS(users, emoticons, 0);

    return { max_users, max_sales };
}

int main()
{
    solution({ {40, 10000}, {25,10000} }, { 7000, 9000 });
    solution({ {40, 2900},{23, 10000},{11, 5200},{5, 5900},{40, 3100},{27, 9200},{32, 6900} },
        { 1300, 1500, 1600, 4900 });
}
