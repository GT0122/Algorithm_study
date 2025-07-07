#include <iostream>

using namespace std;

int search(char** map, int** nmap, int row, int col, char c, int n, int type) {
	nmap[row][col] = 1;

	if (type == 1) {
		if (row > 0 and map[row - 1][col] == c and nmap[row - 1][col] == 0) {
			search(map, nmap, row - 1, col, c, n, type);
		}

		if (row < n - 1 and map[row + 1][col] == c and nmap[row + 1][col] == 0) {
			search(map, nmap, row + 1, col, c, n, type);
		}

		if (col > 0 and map[row][col - 1] == c and nmap[row][col - 1] == 0) {
			search(map, nmap, row, col - 1, c, n, type);
		}

		if (col < n - 1 and map[row][col + 1] == c and nmap[row][col + 1] == 0) {
			search(map, nmap, row, col + 1, c, n, type);
		}
	}
	else {
		if (c == 'B') {
			if (row > 0 and map[row - 1][col] == c and nmap[row - 1][col] == 0) {
				search(map, nmap, row - 1, col, c, n, type);
			}

			if (row < n - 1 and map[row + 1][col] == c and nmap[row + 1][col] == 0) {
				search(map, nmap, row + 1, col, c, n, type);
			}

			if (col > 0 and map[row][col - 1] == c and nmap[row][col - 1] == 0) {
				search(map, nmap, row, col - 1, c, n, type);
			}

			if (col < n - 1 and map[row][col + 1] == c and nmap[row][col + 1] == 0) {
				search(map, nmap, row, col + 1, c, n, type);
			}
		}
		else {
			if (row > 0 and map[row - 1][col] != 'B' and nmap[row - 1][col] == 0) {
				search(map, nmap, row - 1, col, c, n, type);
			}

			if (row < n - 1 and map[row + 1][col] != 'B' and nmap[row + 1][col] == 0) {
				search(map, nmap, row + 1, col, c, n, type);
			}

			if (col > 0 and map[row][col - 1] != 'B' and nmap[row][col - 1] == 0) {
				search(map, nmap, row, col - 1, c, n, type);
			}

			if (col < n - 1 and map[row][col + 1] != 'B' and nmap[row][col + 1] == 0) {
				search(map, nmap, row, col + 1, c, n, type);
			}
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	char** map = new char* [n];
	int** nmap = new int* [n];
	int** camap = new int* [n];

	for (int i = 0; i < n; i++) {
		map[i] = new char[n];
		nmap[i] = new int[n] {0};
		camap[i] = new int[n] {0};

		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nmap[i][j] == 0) {
				search(map, nmap, i, j, map[i][j], n, 1);
				answer++;
			}
		}
	}

	int answerCA = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (camap[i][j] == 0) {
				search(map, camap, i, j, map[i][j], n, 2);
				answerCA++;
			}
		}
	}
	cout << answer << ' ' << answerCA;

	return 0;
}