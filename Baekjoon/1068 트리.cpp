#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[51];
int root{};

void DFS(int num, int deleted_num, int& count)
{
	if (num == deleted_num) {		// 루트 노드가 지워진 노드면 바로 리턴
		return;
	}

	if (v[num].size() == 0) {		// 자식 노드가 없다면 리프노드이므로 count 증가
		++count;
	}
	else {
		for (const auto& n : v[num]) {		// 자식 노드가 있다면 순회
			DFS(n, deleted_num, count);
		}
	}
}

void RemoveTree(int num, int deleted_num)
{
	auto& vec = v[num];
	auto it = find(vec.begin(), vec.end(), deleted_num);

	if (it != vec.end()) {				// 발견하면 삭제
		vec.erase(it);
	}
	else {
		for (const auto& n : vec) {		// 발견 못하면 자식 노드 순회
			RemoveTree(n, deleted_num);
		}
	}
}

int main()
{
	int n{}, parent{}, count{};
	int deleted_num{};

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> parent;

		if (parent == -1) {
			root = i;
		}
		else {
			v[parent].emplace_back(i);
		}
	}

	cin >> deleted_num;
	RemoveTree(root, deleted_num);

	DFS(root, deleted_num, count);
	
	cout << count << "\n";
}