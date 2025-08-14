#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	int* pos[8] = { &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4 };
	int pre = 0;
	int cur = 0;
	long long d1, d2, d3, d4;
	int temp_x, temp_y;
	getline(cin, str);
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == ' ') {
			*pos[cur] = stoi(str.substr(pre, i - pre));
			pre = i + 1;
			cur += 1;
		}
	}
	*pos[cur] = stoi(str.substr(pre, str.length() - pre));

	if((x1 > x2) || (x1 == x2 and y1 > y2)) {
		temp_x = x1;
		temp_y = y1;
		x1 = x2;
		y1 = y2;
		x2 = temp_x;
		y2 = temp_y;
	}
	if((x3 > x4) || (x3 == x4 and y3 > y4)) {
		temp_x = x3;
		temp_y = y3;
		x3 = x4;
		y3 = y4;
		x4 = temp_x;
		y4 = temp_y;
	}

	// 1, 2, 3
	d1 = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	// 1, 2, 4
	d2 = (x1 * y2 + x2 * y4 + x4 * y1) - (y1 * x2 + y2 * x4 + y4 * x1);
	// 3, 4, 1
	d3 = (x3 * y4 + x4 * y1 + x1 * y3) - (y3 * x4 + y4 * x1 + y1 * x3);
	// 3, 4, 2
	d4 = (x3 * y4 + x4 * y2 + x2 * y3) - (y3 * x4 + y4 * x2 + y2 * x3);

	if((d1 * d2 < 0) && (d3 * d4 < 0)) {
		cout << 1 << endl;
	}
	else if((d1 * d2 == 0) && (d3 * d4 == 0)) {
		cout << ((x1 <= x4) && (x2 >= x3)) << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}