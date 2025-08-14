#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	int fIdx, rIdx, len;
	bool rear = false, error = false;
	string p, result = "";
	char c;
	int* pInt;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		cin >> p;
		cin >> n;
		cin >> c;

		pInt = new int[n];
		if (n > 0) {
			for (int j = 0; j < n; j++) {
				cin >> pInt[j];
				cin >> c;
			}
		}
		else {
			cin >> c;
		}

		rear = false;
		error = false;
		fIdx = 0;
		rIdx = n;
		len = p.length();

		for(int j = 0; j < len; j++)
		{
			if(p[j] == 'R')
			{
				if(rear)
					rear = false;
				else
					rear = true;
			}
			else
			{
				if(rear)
					rIdx--;
				else
					fIdx++;
			}

			if(fIdx > rIdx)
			{
				error = true;
				break;
			}
		}

		if (error)
		{
			result += "error";
		}
		else
		{
			result += '[';

			if(rear)
			{
				for(int j = rIdx - 1; j >= fIdx; j--)
				{
					result += to_string(pInt[j]);

					if (j != fIdx)
						result += ',';
				}
			}
			else
			{
				for(int j = fIdx; j < rIdx; j++)
				{
					result += to_string(pInt[j]);

					if (j != rIdx - 1)
						result += ',';
				}
			}
			result += ']';
		}

		result += '\n';

		delete[] pInt;
	}

	cout << result;

	return 0;
}