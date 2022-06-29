#include <iostream>
#include <cmath>

using namespace std;

#define ellapse 

struct Point {
	int x;
	int y;
};

bool get_zero(double a, double b)
{
	if (fabs(a - b) < numeric_limits<double>::epsilon())
		return true;
	return false;
}

int get_crosspoint(Point& a, Point& b, int& r1, int& r2)
{
	// ���� ���� = ���Ѵ�
	
	if (a.x == b.x && a.y == b.y && r1 == r2)
		return -1;

	// ���� �ٸ� - ���� ���ϱ�
	else {
		int diffx = b.x - a.x;
		int diffy = b.y - a.y;
		double d = sqrt(diffx * diffx + diffy * diffy);
		double sum_radius = (double)r1 + (double)r2;

		// ���� ������ ����
		if (d > sum_radius)
			return 0;
		// ���� �������� ����
		if(get_zero(d, sum_radius) || get_zero(d, fabs(r2-r1)))
			return 1;
		// ���� �� ������ ����
		if (sum_radius > d && d > fabs(r2-r1))
			return 2;
		// ���� ���ο��� ������ ����
		if (d < fabs(r2 - r1))
			return 0;

	}
	

}

int main()
{
	int cnt;
	cin >> cnt;

	Point a, b;
	int r1, r2;

	while (cnt) {
		cin >> a.x >> a.y >> r1 >> b.x >> b.y >> r2;
		
		cout << get_crosspoint(a, b, r1, r2) << endl;
		--cnt;
	}

}

// ���� ���� ���ϴ� ����