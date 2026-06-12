#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 이익의 10퍼는 추천인(부모)에게 배분, 10퍼가 1원 미만이면 분배 X
// 배분받은 것 또한 이익으로 쳐서 10퍼 배분해야 함
// 10퍼 분배 시 내림, 

struct Node {
    string name;
    string parent;
    int total;
};

void DivideAmount(unordered_map<string, Node>& um, Node& current, int amount)
{
    // 10 아래면 나눠도 0원이므로 분배 X
    if (amount < 10) {
        current.total += amount;
        return;
    }

    // 현재 조직원이 10퍼 제외하고 가짐
    int n = amount / 10;   // 분배금
    int cur_val = amount - n;   // 분배하고 남은 금액

    current.total += cur_val;

    if (current.parent != "") {
        DivideAmount(um, um[current.parent], n);
    }
}

// 판매원 이름, 참여시킨 추천인 이름, 판매량 데이터, 판매 수량
vector<int> solution(vector<string> enroll, vector<string> referral,
    vector<string> seller, vector<int> amount)
{
    constexpr int PRICE = 100;

    unordered_map<string, Node> um;

    // enroll : 민호를 제외한 조직원 수
    
    // 레퍼럴 : i번째 판매원의 추천인, enroll과 동일
    // 레퍼럴이 없으면 center와 연결
    for (int i = 0; i < enroll.size(); ++i) {
        Node node{};
        node.name = enroll[i];
        if (referral[i] != "-") {
            node.parent = referral[i];
        }
        node.total = 0;

        um.insert({ node.name, node });
    }

    // 셀러 : i번째 이름 = i번째 데이터가 어느 판매원인지
    
    // amount : 셀러와 같음, i번째 집계 데이터의 수량
    for (int i = 0; i < seller.size(); ++i) {
        string name = seller[i];
        int val = PRICE * amount[i];

        DivideAmount(um, um[name], val);
    }

    vector<int> answer(enroll.size(), 0);

    for(int i = 0; i < enroll.size(); ++i){
        answer[i] = um[enroll[i]].total;
    }

    // enroll 순서대로
    return answer;
}

int main()
{
    solution({ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" },
        { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" },
        { "young", "john", "tod", "emily", "mary" }, {12,4,2,5,10 });
    solution({ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" },
        { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" },
        { "sam", "emily", "jaimie", "edward" }, { 2,3,5,4 });
}
