#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, delNum, temp, count = 0;
	int* pNum;
	vector<int> vctStack;

	cin >> n;
	pNum = new int[n];

	for(int i = 0; i < n; i++)
		cin >> pNum[i];

	cin >> delNum;

	vctStack.push_back(delNum);
	pNum[delNum] = -2;

	while(vctStack.size() > 0)
	{
		temp = vctStack.back();
		vctStack.pop_back();

		for(int i = 0; i < n; i++)
		{
			if(pNum[i] == temp)
			{
				pNum[i] = -2;
				vctStack.push_back(i);
			}
		}

	}

	bool bb;
	for(int i = 0; i < n; i++)
	{
		if(pNum[i] != -2)
		{
			bb = true;

			for(int j = 0; j < n; j++)
			{
				if(pNum[j] == i)
				{
					bb = false;
					break;
				}
			}

			if(bb)
				count++;
		}
	}

	cout << count << endl;

	vctStack.clear();
	delete[] pNum;

	return 0;
}