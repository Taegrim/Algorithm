#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s{};
	char type{};
	int count{};
	
	cin >> s;

	type = s[0];
	for (const auto& c : s){
		if (type != c) {
			type = c;
			++count;
		}
	}

	if (count % 2 == 0)
		count /= 2;
	else
		count = count / 2 + 1;

	cout << count << '\n';
}