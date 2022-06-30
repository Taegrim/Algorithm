#include <iostream>

using namespace std;

int r, c, k;
int cnt{}, dist{};
bool reach = false;

void back(int row, int col, char**& arr)
{
	arr[row][col] = '.';
	dist--;
	reach = false;
}

bool check_road(int row, int col, char**& arr)
{
	if (arr[row][col] == '.' && dist < k)
		return true;
	return false;
}

void solve(int row, int col, char**& arr)
{
	
	arr[row][col] = 'A';
	dist++;

	// �̵� �� �������� && �Ÿ��� K�̸� �������� ����
	if (dist == k && arr[0][c - 1] == 'A')
		cnt++;

	// �Ÿ���K�� �ƴ����� ���������� ����
	else if (arr[0][c - 1] == 'A')
		reach = true;
		
	// �ƴϸ� �̵�
	else {
		if (row < r - 1) {
			if (check_road(row + 1, col, arr)) {
				solve(row + 1, col, arr);
				back(row + 1, col, arr);
			}
		}
		if (col < c - 1) {
			if (check_road(row, col + 1, arr)) {
				solve(row, col + 1, arr);
				back(row, col + 1, arr);
			}
		}
		if (row > 0) {
			if (check_road(row - 1, col, arr)) {
				solve(row - 1, col, arr);
				back(row - 1, col, arr);
			}
		}
		if (col > 0) {
			if (check_road(row, col - 1, arr)) {
				solve(row, col - 1, arr);
				back(row, col - 1, arr);
			}
		}
	}
	
}


int main()
{
	cin >> r >> c >> k;

	char** arr = new char* [r];
	for (int i{}; i < r; ++i)
		arr[i] = new char[c];

	for (int i{}; i < r; ++i) 
		for (int j{}; j < c; ++j)
			cin >> arr[i][j];

	solve(r - 1, 0, arr);

	cout << cnt << endl;

	for (int i{}; i < r; ++i)
		delete arr[i];
	delete[] arr;
}