#include <iostream>

using namespace std;

void qsort(char* arrC, int start, int end) {
	if (start >= end) return;

	int index = start;
	int indexR = 0;

	char* right = new char[end - start];

	char stand = arrC[index];

	for (int i = start+1; i < end; i++) {
		if (stand > arrC[i]) {
			arrC[index++] = arrC[i];
		}
		else {
			right[indexR++] = arrC[i];
		}
	}

	arrC[index] = stand;
	for (int i = 0; i < indexR; i++) {
		arrC[index + i + 1] = right[i];
	}

	qsort(arrC, start, index);
	qsort(arrC, index+1, end);
}

void search(char* arrC, char* answer, int index, int indexA, int l, int c) {
	if (indexA == l) {
		int m = 0;
		for (int i = 0; i < l; i++) {
			if (answer[i] == 'a') m++;
			else if (answer[i] == 'e') m++;
			else if (answer[i] == 'i') m++;
			else if (answer[i] == 'o') m++;
			else if (answer[i] == 'u') m++;
		}

		answer[l] = 0;
		
		if(m >= 1 and (l - m) >= 2) cout << answer << endl;
		return;
	}

	for (int i = index; i < c; i++) {
		answer[indexA] = arrC[i];
		search(arrC, answer, i + 1, indexA + 1, l, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, c;

	cin >> l;
	cin >> c;

	char* arrChar = new char[c];

	for (int i = 0; i < c; i++) {
		cin >> arrChar[i];
	}

	qsort(arrChar, 0, c);

	char* answer = new char[l + 1];
	search(arrChar, answer, 0, 0, l, c);

	return 0;
}