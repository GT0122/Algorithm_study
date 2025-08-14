#include <iostream>
#include <cmath>

using namespace std;

int move(int count, int start, int m, int end, int n, char* str) {
	if (count == 1) {
		str[n * 4] = start + 48;
		str[n * 4 + 1] = ' ';
		str[n * 4 + 2] = end + 48;
		str[n * 4 + 3] = '\n';
		return n + 1;
	}

	int num = move(count - 1, start, end, m, n, str);
	str[num * 4] = start + 48;
	str[num * 4 + 1] = ' ';
	str[num * 4 + 2] = end + 48;
	str[num * 4 + 3] = '\n';
	num++;
	num = move(count - 1, m, start, end, num, str);
	
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int n, k;

	cin >> n;

	k = (int)(pow(2, n)) - 1;

	cout << k << endl;

	char* str = new char[k * 4 + 1];

	move(n, 1, 2, 3, 0, str);

	str[k * 4] = 0;
	cout << str;

	return 0;
}