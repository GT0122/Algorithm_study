#include <iostream>
#include <vector>

using namespace std;

int N, L, R;

void search(int A[50][50], int group[50][50], int num, int r, int c) {
	group[r][c] = num;

	int temp;
	
	if (r - 1 >= 0 && group[r - 1][c] == -1) {
		temp = abs(A[r][c] - A[r - 1][c]);
		if (temp >= L && temp <= R) {
			search(A, group, num, r - 1, c);
		}
	}
	if (r + 1 < N && group[r + 1][c] == -1) {
		temp = abs(A[r][c] - A[r + 1][c]);
		if (temp >= L && temp <= R) {
			search(A, group, num, r + 1, c);
		}

	}
	if (c - 1 >= 0 && group[r][c - 1] == -1) {
		temp = abs(A[r][c] - A[r][c - 1]);
		if (temp >= L && temp <= R) {
			search(A, group, num, r, c - 1);
		}

	}
	if (c + 1 < N && group[r][c + 1] == -1) {
		temp = abs(A[r][c] - A[r][c + 1]);
		if (temp >= L && temp <= R) {
			search(A, group, num, r, c + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[50][50]{0, }, group[50][50]{0, };
	vector<int> n_sum, n_count, n_avg;
	int num, n = 0;
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	while (true) {
		for (int i = 0; i < N; i++) fill(group[i], group[i] + N, -1);
				
		num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (group[i][j] == -1) {
					search(A, group, num, i, j);
					num++;
				}
			}
		}

		if (num == N * N) break;

		for (int i = 0; i < num; i++) {
			n_sum.push_back(0);
			n_count.push_back(0);
			n_avg.push_back(0);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (group[i][j] >= 0) {
					n_sum[group[i][j]] += A[i][j];
					n_count[group[i][j]]++;
				}
			}
		}

		for (int i = 0; i < num; i++) n_avg[i] = n_sum[i] / n_count[i];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (group[i][j] >= 0) A[i][j] = n_avg[group[i][j]];
			}
		}

		n++;
		n_sum.clear();
		n_count.clear();
		n_avg.clear();
	}

	cout << n;

	return 0;
}