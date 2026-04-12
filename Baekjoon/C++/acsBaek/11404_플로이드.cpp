#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, s, e, c;

	cin >> n;
	cin >> m;
	vector<vector<int>> arr(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++) arr[i][i] = 0;

	for (int i = 0; i < m; i++) {
		cin >> s;
		cin >> e;
		cin >> c;

		if (arr[s - 1][e - 1] > c) arr[s - 1][e - 1] = c;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INF) cout << 0 << ' ';
			else cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}