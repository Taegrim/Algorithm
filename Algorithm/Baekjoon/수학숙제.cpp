#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 모든 숫자의 앞과뒤에 문자 or 줄의 시작 / 끝 

string GetStr(const string& str, int start, int count)
{
    string s = str.substr(start, count);

    while (s.size() > 1 && s[0] == '0')
    {
        s.erase(s.begin());
    }

    return s;
}

vector<string> solution(vector<string> papers)
{
    vector<string> answer;

    for (const auto& str : papers)
    {
        int start = -1;

        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                // 문자를 처음 만났다면 위치 기록
                if (start == -1)
                {
                    start = i;
                }
            }
            else
            {
                // 문자가 아닌데 기록이 되어있다면 숫자가 끝남
                // 저장 필요
                if (start != -1)
                {
                    string s = GetStr(str, start, i - start);
                    answer.push_back(s);
                    start = -1;
                }
            }
        }

        // 문자열의 끝인데 기록하고 있었다면 마찬가지로 저장
        if (start != -1)
        {
            string s = GetStr(str, start, str.size() - start);
            answer.push_back(s);
            start = -1;
        }
    }
    
    // 우선 길이가 짧은순으로 
    // 길이가 같다면 오름차순
    sort(answer.begin(), answer.end(), [](const string& a, const string& b) {
        if (a.size() == b.size())
        {
            return a < b;
        }
        return a.size() < b.size();
        });

    //for (const auto& str : answer)
    //{
    //    cout << str << " ";
    //}
    //cout << endl;

    return answer;
}

int main()
{
    solution({"lo3za4", "01"});
    solution({"43silos0", "zita002", "le2sim", "231233"});
    solution({"01bond", "02james007", "03bond", "04austinpowers000"});
}
