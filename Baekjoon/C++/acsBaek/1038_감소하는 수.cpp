#include <iostream>

using namespace std;

void search(char str[], int index, int length, int max_length, int* count, int N, char arrC[]) {
	str[length] = arrC[index];

	if (length == max_length - 1)
	{
		*count += 1;
		if (*count < N) str[length] = '\0';
	}
	else {
		for (int i = 0; i < index; i++) {
			if (*count < N) search(str, i, length + 1, max_length, count, N, arrC);
		}
	}

	if (*count < N) str[length] = '\0';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	if (N < 1023) {
		char arrC[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		char str[11] = { '\0', };
		int count = -1, length = 1, index = 0;

		for (int i = 1; i <= 10; i++) {
			if (count == N) break;
			for (int j = i - 1; j < 10; j++) {
				if (count == N) break;
				search(str, j, 0, i, &count, N, arrC);
			}
		}

		cout << str;
	}
	else {
		cout << -1;
	}

	return 0;
}