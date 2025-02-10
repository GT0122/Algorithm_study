#include <iostream>
#include <string>
#include <queue>

#define MAXINT 1000000000;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	int s, d, w;
	int first, second;
	int* nodes;
	vector<pair<int, int>>* vctEdge; 
	vector<pair<int, int>> vctTemp;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> t;

	scanf_s("%d %d %d", &v, &e, &k);

	nodes = new int[v];
	vctEdge = new vector<pair<int, int>>[v];
	
	for(int i = 0; i < v; i++)
		nodes[i] = MAXINT;

	for(int i = 0; i < e; i++)
	{
		scanf_s("%d %d %d", &s, &d, &w);

		vctEdge[s - 1].push_back(make_pair(w, d - 1));
	}
	
	t.push(make_pair(0, k - 1));

	vector<pair<int, int>>::iterator iter;

	while(t.size() > 0)
	{
		first = t.top().first;
		second = t.top().second;
		t.pop();

		if(nodes[second] > first)
		{
			nodes[second] = first;

			vctTemp = vctEdge[second];

			for(iter = vctTemp.begin(); iter < vctTemp.end(); iter++)
			{
				(*iter).first += first;

				t.push(*iter);
			}
		}
	}

	for(int i = 0; i < v; i++)
	{
		if(nodes[i] == 1000000000)
			printf_s("INF\n");
		else
			printf_s("%d\n", nodes[i]);
	}
	
	return 0;
}