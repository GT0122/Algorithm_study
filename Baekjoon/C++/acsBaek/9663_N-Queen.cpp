#include <iostream>

using namespace std;

int search(int* left, int* mid, int* right, int row, int n) {
	int count = 0;

	if (row == n) return 1;

	for (int i = 0; i < row; i++) {
		left[i] -= 1;
		right[i] += 1;
	}

	int* index = new int[n] {0};
	for (int i = 0; i < row; i++) {
		if (left[i] >= 0 and left[i] < n) {
			index[left[i]] = -1;
		}

		index[mid[i]] = -1;

		if (right[i] >= 0 and right[i] < n) {
			index[right[i]] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (index[i] == 0) {
			left[row] = i;
			mid[row] = i;
			right[row] = i;
			count += search(left, mid, right, row + 1, n);
			left[row] = -1;
			mid[row] = -1;
			right[row] = -1;
		}
	}

	for (int i = 0; i < row; i++) {
		left[i] += 1;
		right[i] -= 1;
	}

	delete index;

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* left = new int[n] {-1};
	int* mid = new int[n] {-1};
	int* right = new int[n] {-1};

	int answer = 0;
	for (int i = 0; i < n; i++) {
		left[0] = i;
		mid[0] = i;
		right[0] = i;
		answer += search(left, mid, right, 1, n);
		left[0] = -1;
		mid[0] = -1;
		right[0] = -1;
	}

	cout << answer;

	return 0;
}