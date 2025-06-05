#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s;

int main()
{
	cin >> s;

	sort(s.begin(), s.end(), greater<>());

	cout << s;
}