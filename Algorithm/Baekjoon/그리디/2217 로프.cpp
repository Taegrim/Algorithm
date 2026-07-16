#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> lopes(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> lopes[i];
    }

    sort(lopes.begin(), lopes.end(), greater<int>());

    
    int max_weight = 0;

    // 앞에서부터 i개 로프를 사용한다고 가정
    //  -> 들수있는 최대 무게 = 가장 약한 로프 * count 
    for (int i = 0; i < n; ++i)
    {
        int count = i + 1;

        int weight = lopes[i] * count;
        max_weight = max(max_weight, weight);
    }

    cout << max_weight << "\n";
}
