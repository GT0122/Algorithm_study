#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	int fIdx, rIdx, len;
	bool rear = false, error = false;
	string p, d, result;
	string* pResult;
	int* pInt;

	cin >> t;

	pResult = new string[t];

	for(int i = 0; i < t; i++)
	{
		cin >> p;
		cin >> n;
		cin >> d;

		d = d.substr(1, d.size() - 2);

		pInt = new int[n];

		for(int j = 0; j < n; j++)
		{
			pInt[j] = stoi(d.substr(0, d.find(',')));
			d = d.substr(d.find(',') + 1);
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

		result = "";

		if(error)
			result = "error";
		else
		{
			result += '[';

			if(rear)
			{
				for(int j = rIdx - 1; j >= fIdx; j--)
				{
					result += to_string(pInt[j]);

					if(j != fIdx + 1)
						result += ',';
				}
			}
			else
			{
				for(int j = fIdx; j < rIdx; j++)
				{
					result += to_string(pInt[j]);

					if(j != rIdx - 1)
						result += ',';
				}
			}
			result += ']';

			pResult[i] = result;
		}

		pResult[i] = result;

		delete[] pInt;
	}

	for(int i = 0; i < t; i++)
		cout << pResult[i] << '\n';

	return 0;
}