#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	int* arr = new int[N];
	int* ans = new int[N];
	fill(ans, ans + N, -1);

	for (int i = 0; i < N; i++) cin >> arr[i];

	int *s = new int[N];
	int top = -1;

	for (int i = 0; i < N; i++) {
		while (top > -1 and arr[s[top]] < arr[i]) {
			ans[s[top--]] = arr[i];
		}
		s[++top] = i;
	}

	for (int i = 0; i < N; i++) cout << ans[i] << ' ';

	delete[] arr;
	delete[] ans;
	delete[] s;

	return 0;
}