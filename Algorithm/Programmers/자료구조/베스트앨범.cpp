#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 장르별로 가장 많이 재생된 노래
// 1. 속한 노래가 많이 재생된 장르
// 2. 장르 내에서 많이 재생된 노래
// 3. 장르 내에서 재생횟수가 같다면 고유번호가 낮은 노래

// 장르별로 2개까지만 모아서 앨범 출시

// 베스트 앨범에 들어갈 고유번호 순서대로

struct Data {
    int count;
    int index;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map <string, int> um1;

    // 장르별 데이터
    unordered_map<string, vector<Data>> um2;

    // 어떤 장르가 많이 재생됐는지
    // 장르 중에서 많이 재생된 노래가 뭔지
    for (int i = 0; i < genres.size(); ++i) {
        const string& genre = genres[i];
        const int& play = plays[i];

        um1[genre] += play;
        um2[genre].push_back({ play, i });
    }

    // 장르별 최대 재생수로 정렬
    vector<pair<string, int>> v;
    for (const auto& [genre, count] : um1) {
        v.push_back({ genre, count });
    }
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });

    // 최대 재생수를 가진 장르부터 2개씩 뽑기
    for (const auto& [genre, count] : v) {
        auto& vec = um2[genre];

        sort(vec.begin(), vec.end(), [](const Data& a, const Data& b) {
            if (a.count == b.count) {
                return a.index < b.index;
            }
            return a.count > b.count;
            });

        for (int i = 0; i < 2 && i < vec.size(); ++i) {
            answer.push_back(vec[i].index);
        }
    }

    return answer;
}

int main()
{
    solution({ "classic", "pop", "classic", "classic", "pop" },
        { 500, 600, 150, 800, 2500 });
}
