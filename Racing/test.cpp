#include <iostream>

#include "Point.h"
#include "Rect.h"

using namespace std;

int main() {
	//Point p(2, 2);
	//for (size_t i = 0; i < 50; i++) {
	//	p.RandomizeX(1, 10);
	//	cout << p.GetX() << " " << p.GetY() << endl;
	//}

	Rect r(10, 10, 30, 30);
	cout << "Top : " << r.Top() << endl;
	cout << "Bottom : " << r.Bottom() << endl;
	cout << "Left : " << r.Left() << endl;
	cout << "Right : " << r.Right() << endl;

	return 0;
}