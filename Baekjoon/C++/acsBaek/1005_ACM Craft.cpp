#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, k, w, size;
	int start, end;
	int* pCost;
	int* pTop;
	vector<int>* vctRule;
	vector<int>* vctEtoS;
	int* pResult;
	string str;

	int num, temp, maxnum;
	vector<int> vctNum;
	vector<int>::iterator iter;
	vector<int>::iterator iiter;

	cin >> t;

	pResult = new int[t] { 0 };

	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> k;
		cin.ignore();

		pCost = new int[n];
		pTop = new int[n] { 0 };
		vctRule = new vector<int>[n];
		vctEtoS = new vector<int>[n];

		getline(cin, str);
		for(int j = 0; j < n; j++)
		{
			pCost[j] = stoi(str.substr(0, str.find(' ')));
			str = str.substr(str.find(' ') + 1);
		}

		for(int j = 0; j < k; j++)
		{
			cin >> start;
			cin >> end;

			pTop[end - 1]++;
			vctRule[start - 1].push_back(end - 1);
			vctEtoS[end - 1].push_back(start - 1);
		}

		cin >> w;

		for(int j = 0; j < n; j++)
		{
			if(pTop[j] == 0)
				vctNum.push_back(j);
		}

		size = vctNum.size();

		while(size > 0)
		{
			num = vctNum.back();
			vctNum.pop_back();
			size--;
			
			for(iter = vctRule[num].begin(); iter < vctRule[num].end(); iter++)
			{
				temp = *iter;
				pTop[temp]--;

				if(pTop[temp] == 0)
				{
					vctNum.push_back(temp);
					size++;

					maxnum = 0;

					for(iiter = vctEtoS[temp].begin(); iiter < vctEtoS[temp].end(); iiter++)
						maxnum = max(maxnum, pCost[*iiter]);

					pCost[temp] += maxnum;
				}
			}
		}

		pResult[i] = pCost[w - 1];

		delete[] pCost;
		delete[] pTop;
		vctNum.clear();
		vctRule->clear();
		vctEtoS->clear();
	}

	for(int i = 0; i < t; i++)
		cout << pResult[i] << endl;

	delete[] pResult;

	return 0;
}