#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, tcount, p, t;
	vector<int> truth;
	vector<int>* pVctPP;
	vector<int>* pVctPP2;
	bool* pVisited;
	bool* pParty;

	cin >> n;
	cin >> m;

	pVctPP = new vector<int>[n + 1];
	pVctPP2 = new vector<int>[m + 1]; 
	pVisited = new bool[n + 1] { false };
	pParty = new bool[m + 1] { false };

	cin >> tcount;

	for(int i = 0; i < tcount; i++)
	{
		cin >> t;
		truth.push_back(t);
	}

	for(int i = 0; i < m; i++)
	{
		cin >> p;

		for(int j = 0; j < p; j++)
		{
			cin >> t;
			pVctPP[t].push_back(i);
			pVctPP2[i].push_back(t);
		}
	}

	int num, temp;
	vector<int>::iterator iter;
	vector<int>::iterator iiter;

	while(truth.size() > 0)
	{
		num = truth.back();
		truth.pop_back();

		for(iter = pVctPP[num].begin(); iter < pVctPP[num].end(); iter++)
		{
			temp = *iter;

			if(!pParty[temp])
			{
				for(iiter = pVctPP2[temp].begin(); iiter < pVctPP2[temp].end(); iiter++)
				{
					if(!pVisited[*iiter])
					{
						truth.push_back(*iiter);
						pVisited[*iiter] = true;
					}
				}

				pParty[temp] = true;
			}
		}
	}

	int count = 0;

	for(int i = 0; i < m; i++)
		if(!pParty[i])
			count++;

	cout << count << endl;

	truth.clear();
	pVctPP->clear();
	pVctPP2->clear();
	delete[] pVisited;
	delete[] pParty;

	return 0;
}