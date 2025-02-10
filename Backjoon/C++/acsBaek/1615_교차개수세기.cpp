#include <iostream>
#include <string>

using namespace std;

struct Node {
	int a;
	int b;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;
	cin.ignore();

	int** lines = new int* [n + 1];
	for(int i = 0; i < n + 1; i++) {
		lines[i] = new int[n + 1] {0, };
	}

	Node* nodes = new Node[m];

	string str;
	int index = 0;
	int a = 0, b = 0;
	int tier = 0;
	for(int i = 0; i < m; i++) {
		getline(cin, str);
		index = str.find(' ');
		a = stoi(str.substr(0, index));
		b = stoi(str.substr(index + 1, str.length() - index));
		nodes[i].a = n - a;
		nodes[i].b = b - 1;
		lines[n - a + 1][b]++;
		while(b + (b & -b) < n) {
			tier = (b & -b);
			lines[n - a + 1][b + tier]++;
			b += tier;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			lines[i+1][j] += lines[i][j];
		}
	}

	int row, col;
	long long count = 0;
	for(int i = 0; i < m; i++) {
		row = nodes[i].a;
		col = nodes[i].b;
		if(col > 0 && row > 0) {
			while(col) {
				count += lines[row][col];
				col -= (col & -col);
			}
		}
	}

	cout << count;
	return 0;
}