#include <iostream>
#include <vector>

using namespace std;

// X -> X+YF
// Y -> FX-Y
// FX 시작

int n, p, l;    // 세대, p번째 글자부터 l개 글자

constexpr int MAX = 1000000000 + 1;
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

vector<int> len(51, -1); // len[i] : X나 Y를 i번 진화한 후의 길이

void PreCalc()
{
    // X 나 Y를 치환하면 X,Y가 하나씩 나오고, 치환과 상관없는 값이 2개 나옴
    //  -> 치환해야할 문자가 2배, 치환과 상관없는 문자 2개 추가
    len[0] = 1;
    for (int i = 1; i <= 50; ++i)
    {
        len[i] = min(MAX, len[i - 1] * 2 + 2);
    }
}

// curve를 generations 진화시킨 결과에서 skip번째 문자 반환
char GetChar(const string& curve, int generations, int skip)
{
    if (generations == 0)
    {
        if (skip < curve.size())
        {
            return curve[skip];
        }
        else
        {
            cout << "에러!\n";
        }
    }

    for (char c : curve)
    {
        // 확장해야하는 문자라면
        if (c == 'X' || c == 'Y')
        {
            // generations만큼 진화했을때 길이가 skip보다 작다면 건너뜀
            if (skip >= len[generations])
            {
                skip -= len[generations];
            }
            else
            {
                // 진화했을때 범위 내에 있다면
                if (c == 'X')
                {
                    return GetChar(EXPAND_X, generations - 1, skip);
                }
                else
                {
                    return GetChar(EXPAND_Y, generations - 1, skip);
                }
            }
        }
        else if (skip > 0)
        {
            // 확장되는 문자가 아니면 한칸 건너뜀
            --skip;
        }
        else
        {
            // 답을 찾았다면
            return c;
        }
    }

    return '?';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    PreCalc();

    while (t--)
    {
        // p 는 1 based
        cin >> n >> p >> l;
        --p;

        for (int i = 0; i < l; ++i)
        {
            cout << GetChar("FX", n, p + i);
        }
        cout << "\n";
    }
}
