#include <iostream>
#include <algorithm>

using namespace std;

int result = 0;

void search(int arrC[][20], int* alpha, int n, int r, int c, int R, int C) {
	result = max(result, n);
	if (result >= 26) return;

	alpha[arrC[r][c]] = 1;

	if (r - 1 >= 0 and !(alpha[arrC[r - 1][c]] & 1)) {
		search(arrC, alpha, n + 1, r - 1, c, R, C);
	}
	if (r + 1 < R and !(alpha[arrC[r + 1][c]] & 1)) {
		search(arrC, alpha, n + 1, r + 1, c, R, C);
	}
	if (c - 1 >= 0 and !(alpha[arrC[r][c - 1]] & 1)) {
		search(arrC, alpha, n + 1, r, c - 1, R, C);
	}
	if (c + 1 < C and !(alpha[arrC[r][c + 1]] & 1)) {
		search(arrC, alpha, n + 1, r, c + 1, R, C);
	}

	alpha[arrC[r][c]] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arrC[20][20]{};
	int alpha[26]{ 0, };

	int R, C;
	cin >> R >> C;

	char c;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> c;
			arrC[i][j] = c - 65;
		}
	}

	search(arrC, alpha, 1, 0, 0, R, C);

	cout << result;

	return 0;
}