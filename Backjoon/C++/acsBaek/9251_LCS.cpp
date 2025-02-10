#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int len, len2;
	string str1, str2;
	int** p2Int;

	cin >> str1;
	cin >> str2;

	p2Int = new int* [str1.length() + 1];

	len = str1.length() + 1;
	len2 = str2.length() + 1;

	p2Int[0] = new int[len2]();
	bool bb = false;

	for(int i = 1; i < len; i++)
	{
		p2Int[i] = new int[len2]();
		memcpy(p2Int[i], p2Int[i - 1], sizeof(int) * len2);

		bb = false;

		for(int j = 1; j < len2; j++)
		{
			if(str1[i - 1] == str2[j - 1])
			{
				p2Int[i][j] = p2Int[i - 1][j - 1] + 1;
				bb = true;
			}
			else if(bb)
				p2Int[i][j] = max(p2Int[i][j - 1], p2Int[i][j]);
		}
	}

	std::cout << p2Int[len - 1][len2 - 1] << endl;

	for(int i = 0; i < len; i++)
		delete[] p2Int[i];

	delete[] p2Int;

	return 0;
}